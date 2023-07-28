/* SPDX-License-Identifier: GPL-2.0-only */

#include <baseboard/variants.h>
#include <bootblock_common.h>
#include <ec/ec.h>
#include <soc/gpio.h>
#include <variant/ec.h>

void bootblock_mainboard_early_init(void)
{
	const struct pad_config *pads;
	size_t num;

	pads = variant_early_gpio_table(&num);
	gpio_configure_pads(pads, num);
}

void bootblock_mainboard_init(void)
{
	mainboard_ec_init();
}