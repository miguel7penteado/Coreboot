/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef LINK_ONBOARD_H
#define LINK_ONBOARD_H

#define BOARD_LIGHTSENSOR_NAME		"lightsensor"
#define BOARD_LIGHTSENSOR_I2C_ADDR	0x44
#define BOARD_LIGHTSENSOR_IRQ		0

#define BOARD_TRACKPAD_NAME		"trackpad"
#define BOARD_TRACKPAD_I2C_ADDR	0x4b
#define BOARD_TRACKPAD_IRQ		20
#define BOARD_TRACKPAD_WAKE_GPIO	0x1c

#define BOARD_TOUCHSCREEN_NAME		"touchscreen"
#define BOARD_TOUCHSCREEN_I2C_ADDR	0x4a
#define BOARD_TOUCHSCREEN_IRQ		22
#define BOARD_TOUCHSCREEN_WAKE_GPIO	0x1e

#define GPIO_REC_MODE	9

#define GPIO_SPI_WP	57

#define GMBUS_PIN_VGADDC	2
#define GMBUS_PIN_PANEL		3

#endif