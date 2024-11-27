#ifndef __SELF_GPIO_H
#define __SELF_GPIO_H

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_RED_PIN  48
#define LED_GREEN_PIN 47
#define BUTTON_PIN 0

void gpio_init(void);

void gpio_pin_set(gpio_num_t gpio_num);

void gpio_pin_reset(gpio_num_t gpio_num);

_Bool get_button_value(gpio_num_t gpio_num);

#endif
