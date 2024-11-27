#include "../Inc/self_gpio.h"

//配置输出寄存器
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<LED_RED_PIN | 1ULL<<LED_GREEN_PIN)

void led_gpio_config(void)
{
    gpio_config_t gpio_init_struct = {0};

    esp_rom_gpio_pad_select_gpio(LED_RED_PIN | LED_GREEN_PIN);

    gpio_init_struct.intr_type = GPIO_INTR_DISABLE;
    gpio_init_struct.mode = GPIO_MODE_OUTPUT;
    gpio_init_struct.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_init_struct.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_init_struct.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;

    gpio_config(&gpio_init_struct);

    gpio_set_level(LED_RED_PIN, 1);
    gpio_set_level(LED_GREEN_PIN, 1);
}

void led_on(gpio_num_t gpio_num)
{
    gpio_set_level(gpio_num, 0);
}

void led_off(gpio_num_t gpio_num)
{
    gpio_set_level(gpio_num, 1);
}