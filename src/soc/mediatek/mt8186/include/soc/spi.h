/* SPDX-License-Identifier: GPL-2.0-only */

/*
 * This file is created based on MT8186 Functional Specification
 * Chapter number: 5.6
 */

#ifndef MTK_MT8186_SPI_H
#define MTK_MT8186_SPI_H

#include <soc/spi_common.h>

#define SPI_BUS_NUMBER 6

#define GET_SCK_REG(x) x->spi_cfg2_reg
#define GET_TICK_DLY_REG(x) x->spi_cfg1_reg

DEFINE_BITFIELD(SPI_CFG_CS_HOLD, 15, 0)
DEFINE_BITFIELD(SPI_CFG_CS_SETUP, 31, 16)

DEFINE_BITFIELD(SPI_CFG_SCK_LOW, 15, 0)
DEFINE_BITFIELD(SPI_CFG_SCK_HIGH, 31, 16)

DEFINE_BITFIELD(SPI_CFG1_CS_IDLE, 7, 0)
DEFINE_BITFIELD(SPI_CFG1_PACKET_LOOP, 15, 8)
DEFINE_BITFIELD(SPI_CFG1_PACKET_LENGTH, 28, 16)
DEFINE_BITFIELD(SPI_TICK_DLY, 31, 29)

enum {
	SPI_NOR_GPIO_SET0 = 0,
	SPI_NOR_GPIO_SET1,
	SPI_NOR_GPIO_SET_NUM,
};

void mtk_snfc_init(int gpio_set);

#endif