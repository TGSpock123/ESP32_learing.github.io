#include "../inc/self_gpio.h"

#define GPIO_OUTPUT_PIN_SEL  (1ULL << LED_RED_PIN | 1ULL << LED_GREEN_PIN)
#define GPIO_INPUT_PIN_SEL (1ULL << BUTTON_PIN);

void gpio_init(void)
{
    gpio_config_t gpio_init_struct = {0};

    esp_rom_gpio_pad_select_gpio(LED_RED_PIN | LED_GREEN_PIN | BUTTON_PIN);

    gpio_init_struct.intr_type = GPIO_INTR_DISABLE;
    gpio_init_struct.mode = GPIO_MODE_OUTPUT;
    gpio_init_struct.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_init_struct.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_init_struct.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;

    gpio_config(&gpio_init_struct);
    
    gpio_init_struct.mode = GPIO_MODE_INPUT;
    gpio_init_struct.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    
    gpio_config(&gpio_init_struct);
}

void gpio_pin_set(gpio_num_t gpio_num)
{
    gpio_set_level(gpio_num, 0);
}

void gpio_pin_reset(gpio_num_t gpio_num)
{
    gpio_set_level(gpio_num, 1);
}

_Bool get_button_value(gpio_num_t gpio_num)
{
  _Bool return_value = 1;

  if (gpio_get_level(gpio_num) == 0)
  {
    vTaskDelay(50 / portTICK_PERIOD_MS);
    return_value = (gpio_get_level(gpio_num) == 0) ? 0 : 1;
    while (gpio_get_level(gpio_num) == 0);
  }

  return return_value;
}
