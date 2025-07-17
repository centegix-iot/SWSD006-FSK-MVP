/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <app.h>
#include <zephyr/logging/log.h>
#include <sidewalk_version.h>

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define RADVCC_NODE DT_ALIAS(radvcc)
#define BUTSIG_NODE DT_ALIAS(butsig)

static const struct gpio_dt_spec radvcc_gpio  = GPIO_DT_SPEC_GET(RADVCC_NODE, gpios);
static const struct gpio_dt_spec butsig_gpio  = GPIO_DT_SPEC_GET(BUTSIG_NODE, gpios);

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_SIDEWALK_LOG_LEVEL);

int main(void)
{
	gpio_pin_configure_dt(&radvcc_gpio, GPIO_OUTPUT_ACTIVE);
    gpio_pin_set_dt(&radvcc_gpio, 1);
    
    gpio_pin_configure_dt(&butsig_gpio, GPIO_OUTPUT_ACTIVE);
    gpio_pin_set_dt(&butsig_gpio, 1);
	
	PRINT_SIDEWALK_VERSION();

	app_start();

	return 0;
}
