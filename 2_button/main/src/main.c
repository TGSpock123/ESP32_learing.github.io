#include "../inc/main.h"

void app_main(void)
{
  _Bool toggle_key = 0;

  gpio_init();

  gpio_pin_reset(LED_RED_PIN);
  gpio_pin_set(LED_GREEN_PIN);

  while(1)
  {
    vTaskDelay(20/portTICK_PERIOD_MS);

    if(get_button_value(BUTTON_PIN) == 0)
    {
      if(!toggle_key)
      {
        gpio_pin_reset(LED_GREEN_PIN);
        gpio_pin_set(LED_RED_PIN);
      }else
      {
        gpio_pin_reset(LED_RED_PIN);
        gpio_pin_set(LED_GREEN_PIN);
      }

      toggle_key = !toggle_key;
    }
  }
}
