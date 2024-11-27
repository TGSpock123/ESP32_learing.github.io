#include "../Inc/main.h"

void app_main(void)
{
  led_gpio_config();
  printf("Hello ESP32. \n");
  
  for(;;)
  {
    led_on(LED_GREEN_PIN);
    vTaskDelay(500/portTICK_PERIOD_MS);
    led_on(LED_RED_PIN);
    vTaskDelay(500/portTICK_PERIOD_MS);
    led_off(LED_GREEN_PIN);
    vTaskDelay(500/portTICK_PERIOD_MS);
    led_off(LED_RED_PIN);
    vTaskDelay(500/portTICK_PERIOD_MS);
  }
}