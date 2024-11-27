#ifndef _GPIO_H_
#define _GPIO_H_

#include "driver/gpio.h"

#define  LED_RED_PIN  48
#define LED_GREEN_PIN 47

void led_gpio_config(void);

void led_on(gpio_num_t gpio_num);

void led_off(gpio_num_t gpio_num);
#endif