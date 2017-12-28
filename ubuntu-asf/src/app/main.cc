#include "asf/asf.h"
//#include "peripheral/button/sw0.h"
//#include "peripheral/led/io1led.h"
//#include "peripheral/led/led0.h"

// auto main() -> int {
//  system_init();
//  delay_init();
//  peripheral::Io1Led led;
//  //peripheral::Sw0 button;
//  //peripheral::Led0 led;
//  //while (true) {
//  //  button.IsPressed() ? led.On() : led.Off();
//  //}
//}

#define CONF_PWM_MODULE LED_0_PWM4CTRL_MODULE
#define CONF_PWM_CHANNEL LED_0_PWM4CTRL_CHANNEL
#define CONF_PWM_OUTPUT LED_0_PWM4CTRL_OUTPUT
#define CONF_PWM_OUT_PIN LED_0_PWM4CTRL_PIN
#define CONF_PWM_OUT_MUX LED_0_PWM4CTRL_MUX

#define CONF_TCC_CAPTURE_CHANNEL 1
#define CONF_TCC_EVENT_GENERATOR EVSYS_ID_GEN_TCC0_MCX_0
#define CONF_TCC_EVENT_USER EVSYS_ID_USER_TCC0_MC_1

struct tcc_module tcc_instance;
uint16_t capture_values[3] = {0, 0, 0};
struct dma_resource capture_dma_resource;
COMPILER_ALIGNED(16) DmacDescriptor capture_dma_descriptor;
struct events_resource capture_event_resource;
uint16_t compare_values[3] = {(0x1000 / 4), (0x1000 * 2 / 4), (0x1000 * 3 / 4)};
struct dma_resource compare_dma_resource;
COMPILER_ALIGNED(16) DmacDescriptor compare_dma_descriptor;

static void config_event_for_capture(void) {
  struct events_config config;
  events_get_config_defaults(&config);
  config.generator = CONF_TCC_EVENT_GENERATOR;
  config.edge_detect = EVENTS_EDGE_DETECT_RISING;
  config.path = EVENTS_PATH_SYNCHRONOUS;
  config.clock_source = GCLK_GENERATOR_0;
  events_allocate(&capture_event_resource, &config);
  events_attach_user(&capture_event_resource, CONF_TCC_EVENT_USER);
}

static void config_dma_for_capture(void) {
  struct dma_resource_config config;
  dma_get_config_defaults(&config);
  config.trigger_action = DMA_TRIGGER_ACTON_BEAT;
  config.peripheral_trigger = CONF_CAPTURE_TRIGGER;
  dma_allocate(&capture_dma_resource, &config);
  struct dma_descriptor_config descriptor_config;
  dma_descriptor_get_config_defaults(&descriptor_config);
  descriptor_config.block_transfer_count = 3;
  descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
  descriptor_config.step_selection = DMA_STEPSEL_SRC;
  descriptor_config.src_increment_enable = false;
  descriptor_config.source_address =
      (uint32_t)&CONF_PWM_MODULE->CC[CONF_TCC_CAPTURE_CHANNEL];
  descriptor_config.destination_address =
      (uint32_t)capture_values + sizeof(capture_values);
  dma_descriptor_create(&capture_dma_descriptor, &descriptor_config);
  dma_add_descriptor(&capture_dma_resource, &capture_dma_descriptor);
  dma_add_descriptor(&capture_dma_resource, &capture_dma_descriptor);
  dma_start_transfer_job(&capture_dma_resource);
}

static void config_dma_for_wave(void) {
  struct dma_resource_config config;
  dma_get_config_defaults(&config);
  config.trigger_action = DMA_TRIGGER_ACTON_BEAT;
  config.peripheral_trigger = CONF_COMPARE_TRIGGER;
  dma_allocate(&compare_dma_resource, &config);
  struct dma_descriptor_config descriptor_config;
  dma_descriptor_get_config_defaults(&descriptor_config);
  descriptor_config.block_transfer_count = 3;
  descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
  descriptor_config.dst_increment_enable = false;
  descriptor_config.source_address =
      (uint32_t)compare_values + sizeof(compare_values);
  descriptor_config.destination_address =
      (uint32_t)&CONF_PWM_MODULE->CC[CONF_PWM_CHANNEL];
  dma_descriptor_create(&compare_dma_descriptor, &descriptor_config);
  dma_add_descriptor(&compare_dma_resource, &compare_dma_descriptor);
  dma_add_descriptor(&compare_dma_resource, &compare_dma_descriptor);
  dma_start_transfer_job(&compare_dma_resource);
}

static void configure_tcc(void) {
  struct tcc_config config_tcc;
  tcc_get_config_defaults(&config_tcc, CONF_PWM_MODULE);
  config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV1024;
  config_tcc.counter.period = 0x1000;
  config_tcc.compare.channel_function[CONF_TCC_CAPTURE_CHANNEL] =
      TCC_CHANNEL_FUNCTION_CAPTURE;
  config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
  config_tcc.compare.wave_polarity[CONF_PWM_CHANNEL] = TCC_WAVE_POLARITY_0;
  config_tcc.compare.match[CONF_PWM_CHANNEL] = compare_values[2];
  config_tcc.pins.enable_wave_out_pin[CONF_PWM_OUTPUT] = true;
  config_tcc.pins.wave_out_pin[CONF_PWM_OUTPUT] = CONF_PWM_OUT_PIN;
  config_tcc.pins.wave_out_pin_mux[CONF_PWM_OUTPUT] = CONF_PWM_OUT_MUX;
  tcc_init(&tcc_instance, CONF_PWM_MODULE, &config_tcc);
  struct tcc_events events_tcc = {
      .input_config[0].modify_action = false,
      .input_config[1].modify_action = false,
      .output_config.modify_generation_selection = false,
      .generate_event_on_channel[CONF_PWM_CHANNEL] = true,
      .on_event_perform_channel_action[CONF_TCC_CAPTURE_CHANNEL] = true};
  tcc_enable_events(&tcc_instance, &events_tcc);
  config_event_for_capture();
  config_dma_for_capture();
  config_dma_for_wave();
  tcc_enable(&tcc_instance);
}

int main(void) {
  configure_tcc();

  struct tcc_module tcc_instance;

  struct tcc_config config_tcc;
  tcc_get_config_defaults(&config_tcc, CONF_PWM_MODULE);

  config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV1024;
  config_tcc.counter.period = 0x1000;
  config_tcc.compare.channel_function[CONF_TCC_CAPTURE_CHANNEL] =
      TCC_CHANNEL_FUNCTION_CAPTURE;
  config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
  config_tcc.compare.wave_polarity[CONF_PWM_CHANNEL] = TCC_WAVE_POLARITY_0;
  config_tcc.compare.match[CONF_PWM_CHANNEL] = compare_values[2];

  config_tcc.pins.enable_wave_out_pin[CONF_PWM_OUTPUT] = true;
  config_tcc.pins.wave_out_pin[CONF_PWM_OUTPUT] = CONF_PWM_OUT_PIN;
  config_tcc.pins.wave_out_pin_mux[CONF_PWM_OUTPUT] = CONF_PWM_OUT_MUX;

  tcc_init(&tcc_instance, CONF_PWM_MODULE, &config_tcc);

  struct tcc_events events_tcc = {
      .input_config[0].modify_action = false,
      .input_config[1].modify_action = false,
      .output_config.modify_generation_selection = false,
      .generate_event_on_channel[CONF_PWM_CHANNEL] = true,
      .on_event_perform_channel_action[CONF_TCC_CAPTURE_CHANNEL] = true};
  tcc_enable_events(&tcc_instance, &events_tcc);

  struct events_resource capture_event_resource;

  struct events_config config;

  events_get_config_defaults(&config);

  config.generator = CONF_TCC_EVENT_GENERATOR;
  config.edge_detect = EVENTS_EDGE_DETECT_RISING;
  config.path = EVENTS_PATH_SYNCHRONOUS;
  config.clock_source = GCLK_GENERATOR_0;

  events_allocate(&capture_event_resource, &config);

  events_attach_user(&capture_event_resource, CONF_TCC_EVENT_USER);

  struct dma_resource capture_dma_resource;

  struct dma_resource_config config;

  dma_get_config_defaults(&config);

  config.trigger_action = DMA_TRIGGER_ACTON_BEAT;
  config.peripheral_trigger = CONF_CAPTURE_TRIGGER;

  dma_allocate(&capture_dma_resource, &config);

  COMPILER_ALIGNED(16) DmacDescriptor capture_dma_descriptor;

  struct dma_descriptor_config descriptor_config;

  dma_descriptor_get_config_defaults(&descriptor_config);

  descriptor_config.block_transfer_count = 3;
  descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
  descriptor_config.step_selection = DMA_STEPSEL_SRC;
  descriptor_config.src_increment_enable = false;
  descriptor_config.source_address =
      (uint32_t)&CONF_PWM_MODULE->CC[CONF_TCC_CAPTURE_CHANNEL];
  descriptor_config.destination_address =
      (uint32_t)capture_values + sizeof(capture_values);

  dma_descriptor_create(&capture_dma_descriptor, &descriptor_config);

  dma_add_descriptor(&capture_dma_resource, &capture_dma_descriptor);
  dma_add_descriptor(&capture_dma_resource, &capture_dma_descriptor);

  dma_start_transfer_job(&capture_dma_resource);

  struct dma_resource compare_dma_resource;
  struct dma_resource_config config;
  dma_get_config_defaults(&config);
  config.trigger_action = DMA_TRIGGER_ACTON_BEAT;
  config.peripheral_trigger = CONF_COMPARE_TRIGGER;
  dma_allocate(&compare_dma_resource, &config);

  COMPILER_ALIGNED(16) DmacDescriptor compare_dma_descriptor;
  struct dma_descriptor_config descriptor_config;
  dma_descriptor_get_config_defaults(&descriptor_config);
  descriptor_config.block_transfer_count = 3;
  descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
  descriptor_config.dst_increment_enable = false;
  descriptor_config.source_address =
      (uint32_t)compare_values + sizeof(compare_values);
  descriptor_config.destination_address =
      (uint32_t)&CONF_PWM_MODULE->CC[CONF_PWM_CHANNEL];
  dma_descriptor_create(&compare_dma_descriptor, &descriptor_config);

  dma_add_descriptor(&compare_dma_resource, &compare_dma_descriptor);
  dma_add_descriptor(&compare_dma_resource, &compare_dma_descriptor);
  dma_start_transfer_job(&compare_dma_resource);

  tcc_enable(&tcc_instance);

  while (true)
    ;
}
