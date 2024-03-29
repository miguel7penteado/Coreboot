/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	/* ------- GPIO Group GPD ------- */
	PAD_CFG_NF(GPD0, UP_20K, PWROK, NF1), // PM_BATLOW#
	PAD_CFG_NF(GPD1, NATIVE, PWROK, NF1), // AC_PRESENT
	PAD_CFG_NF(GPD2, NATIVE, PWROK, NF1), // PCH_LAN_WAKE#
	PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1), // PWR_BTN#
	PAD_CFG_NF(GPD4, NONE, PWROK, NF1), // SUSB#_PCH
	PAD_CFG_NF(GPD5, NONE, PWROK, NF1), // SUSC#_PCH
	PAD_CFG_NF(GPD6, NONE, PWROK, NF1), // SLP_A#
	PAD_CFG_GPO(GPD7, 0, DEEP), // GPD_7
	PAD_CFG_NF(GPD8, NONE, PWROK, NF1), // SUS_CLK
	PAD_CFG_GPO(GPD9, 0, PWROK), // SLP_WLAN#
	PAD_CFG_NF(GPD10, NONE, PWROK, NF1), // SLP_S5#
	PAD_CFG_GPO(GPD11, 1, DEEP),

	/* ------- GPIO Group GPP_A ------- */
	PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1), // ESPI_IO0_EC
	PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1), // ESPI_IO1_EC
	PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1), // ESPI_IO2_EC
	PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1), // ESPI_IO3_EC
	PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1), // ESPI_CS_EC#
	PAD_CFG_NF(GPP_A5, UP_20K, DEEP, NF1), // SERIRQ_ESPI_ALERT0
	PAD_CFG_GPO(GPP_A6, 1, DEEP),
	PAD_CFG_GPO(GPP_A7, 1, DEEP),
	PAD_CFG_GPO(GPP_A8, 1, DEEP), // GPP_A8
	PAD_CFG_NF(GPP_A9, DN_20K, DEEP, NF1), // ESPI_CLK_EC
	PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1), // ESPI_RESET#
	PAD_CFG_GPO(GPP_A11, 1, DEEP),
	PAD_CFG_GPO(GPP_A12, 1, DEEP),
	PAD_CFG_GPO(GPP_A13, 1, PLTRST), // BT_EN
	// GPP_A14 (DGPU_PWR_EN) configured in bootblock
	_PAD_CFG_STRUCT(GPP_A15, 0x86880100, 0x0000), // G_DP_A_HPD_L
	PAD_CFG_NF(GPP_A16, NONE, DEEP, NF1), // USB_OC3#
	PAD_CFG_GPI_INT(GPP_A17, NONE, PLTRST, LEVEL), // TP_ATTN#
	_PAD_CFG_STRUCT(GPP_A18, 0x86880100, 0x0000), // HDMI_HPD
	PAD_CFG_GPI(GPP_A19, NONE, DEEP), // DGPU_PWRGD_R
	PAD_CFG_GPO(GPP_A20, 1, DEEP), // DGPU_OVRM
	PAD_CFG_GPO(GPP_A21, 1, DEEP), // GPIO_LANRTD3
	PAD_CFG_GPO(GPP_A22, 1, DEEP),
	PAD_CFG_GPO(GPP_A23, 1, DEEP),

	/* ------- GPIO Group GPP_B ------- */
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1), // VCCIN_AUX_VID0
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1), // VCCIN_AUX_VID1
	// GPP_B2 (DGPU_RST#_PCH) configured in bootblock
	PAD_CFG_GPI(GPP_B3, NONE, DEEP), // SCI#
	PAD_CFG_GPI(GPP_B4, NONE, DEEP), // SWI#
	_PAD_CFG_STRUCT(GPP_B5, 0x44000a01, 0x0000), // GPPB_I2C2_SDA
	_PAD_CFG_STRUCT(GPP_B6, 0x44000a01, 0x0000), // GPPB_I2C2_SCL
	PAD_CFG_GPO(GPP_B7, 1, DEEP),
	PAD_CFG_GPO(GPP_B8, 1, DEEP),
	PAD_CFG_GPO(GPP_B9, 1, DEEP),
	PAD_CFG_GPO(GPP_B10, 1, DEEP),
	PAD_CFG_NF(GPP_B11, NONE, RSMRST, NF1), // GPP_B11
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1), // SLP_S0#
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1), // SYS_RESET#
	PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1), // GPP_B14
	PAD_CFG_GPO(GPP_B15, 1, DEEP),
	PAD_CFG_GPO(GPP_B16, 1, DEEP),
	PAD_CFG_GPO(GPP_B17, 1, DEEP),
	PAD_CFG_GPO(GPP_B18, 0, DEEP), // GPP_B18
	PAD_CFG_GPO(GPP_B19, 1, DEEP),
	PAD_CFG_GPO(GPP_B20, 1, DEEP),
	PAD_CFG_GPO(GPP_B21, 1, DEEP),
	PAD_CFG_GPO(GPP_B22, 1, DEEP),
	PAD_CFG_GPO(GPP_B23, 0, DEEP), // GPP_B23

	/* ------- GPIO Group GPP_C ------- */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1), // SMB_CLK
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1), // SMB_DATA
	PAD_CFG_GPO(GPP_C2, 1, PLTRST), // M2_SSD1_PWR_EN
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1), // SML0_CLK
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1), // SML0_DATA
	PAD_CFG_GPO(GPP_C5, 0, DEEP), // GPP_C5
	PAD_CFG_NF(GPP_C6, NONE, DEEP, NF1), // SML1_CLK
	PAD_CFG_NF(GPP_C7, NONE, DEEP, NF1), // SML1_DATA
	PAD_NC(GPP_C8, NONE),
	PAD_NC(GPP_C9, NONE),
	PAD_NC(GPP_C10, NONE),
	PAD_NC(GPP_C11, NONE),
	PAD_NC(GPP_C12, NONE),
	PAD_NC(GPP_C13, NONE),
	PAD_NC(GPP_C14, NONE),
	PAD_NC(GPP_C15, NONE),
	PAD_NC(GPP_C16, NONE),
	PAD_NC(GPP_C17, NONE),
	PAD_NC(GPP_C18, NONE),
	PAD_NC(GPP_C19, NONE),
	PAD_NC(GPP_C20, NONE),
	PAD_NC(GPP_C21, NONE),
	PAD_NC(GPP_C22, NONE),
	PAD_NC(GPP_C23, NONE),

	/* ------- GPIO Group GPP_D ------- */
	PAD_CFG_GPO(GPP_D0, 1, DEEP), // SB_BLON
	PAD_CFG_GPO(GPP_D1, 1, DEEP),
	PAD_CFG_GPO(GPP_D2, 0, DEEP), // ROM_I2C_EN
	PAD_CFG_GPO(GPP_D3, 1, DEEP),
	PAD_CFG_GPO(GPP_D4, 0, DEEP), // PS8461_SW
	// GPP_D5 (PEX_SSD2_CLKREQ#) configured by FSP
	PAD_CFG_GPO(GPP_D6, 1, DEEP),
	// GPP_D7 (WLAN_CLKREQ#) configured by FSP
	// GPP_D8 (PEG_CLKREQ#) configured by FSP
	PAD_CFG_GPO(GPP_D9, 1, DEEP),
	PAD_CFG_GPO(GPP_D10, 0, DEEP), // GPP_D10
	_PAD_CFG_STRUCT(GPP_D11, 0x44001700, 0x3c00),
	PAD_CFG_GPO(GPP_D12, 0, DEEP), // GPP_D12
	PAD_CFG_GPI(GPP_D13, NONE, DEEP), // WLAN_W AKEUP#
	PAD_CFG_GPO(GPP_D14, 1, PLTRST), // M2_SSD2_PWR_EN
	PAD_CFG_GPO(GPP_D15, 1, DEEP),
	PAD_CFG_GPO(GPP_D16, 1, DEEP),
	PAD_CFG_GPO(GPP_D17, 1, DEEP),
	PAD_CFG_GPO(GPP_D18, 1, DEEP),
	PAD_CFG_GPO(GPP_D19, 1, DEEP),

	/* ------- GPIO Group GPP_E ------- */
	PAD_CFG_GPI(GPP_E0, NONE, DEEP), // CNVI_W AKE#
	_PAD_CFG_STRUCT(GPP_E1, 0x40100100, 0x3000), // TPM_PIRQ#
	PAD_CFG_GPI(GPP_E2, NONE, DEEP), // BOARD_ID2
	PAD_CFG_GPO(GPP_E3, 1, PLTRST), // PCH_WLAN_EN
	PAD_CFG_GPO(GPP_E4, 0, PLTRST),
	PAD_CFG_GPO(GPP_E5, 0, DEEP),
	PAD_CFG_GPO(GPP_E6, 0, DEEP), // GPP_E6
	PAD_CFG_GPI(GPP_E7, NONE, DEEP), // SMI#
	PAD_CFG_GPI(GPP_E8, NONE, DEEP), // SLP_DRAM#
	PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1), // USB_OC0#
	PAD_CFG_GPO(GPP_E10, 1, DEEP),
	PAD_CFG_GPI(GPP_E11, NONE, DEEP), // BOARD_ID1
	PAD_CFG_GPO(GPP_E12, 1, DEEP),
	PAD_CFG_GPI(GPP_E13, NONE, DEEP), // BOARD_ID4
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1), // PCH_EDP_HPD
	PAD_CFG_GPO(GPP_E15, 1, DEEP), // CCD_FW_WP#
	PAD_CFG_GPO(GPP_E16, 1, DEEP),
	PAD_CFG_GPI(GPP_E17, NONE, DEEP), // BOARD_ID3
	PAD_NC(GPP_E18, NATIVE), // GPP_E18_TBT_LSX0_TXD
	PAD_NC(GPP_E19, NATIVE), // GPP_E19_TBT_LSX0_RXD
	PAD_CFG_GPO(GPP_E20, 1, DEEP),
	PAD_CFG_GPO(GPP_E21, 0, DEEP), // GPP_E21
	PAD_CFG_GPO(GPP_E22, 1, DEEP),
	PAD_CFG_GPO(GPP_E23, 1, DEEP),

	/* ------- GPIO Group GPP_F ------- */
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1), // CNVI_BRI_DT
	PAD_CFG_NF(GPP_F1, UP_20K, DEEP, NF1), // CNVI_BRI_RSP
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1), // CNVI_RGI_DT
	PAD_CFG_NF(GPP_F3, UP_20K, DEEP, NF1), // CNVI_RGI_RSP
	PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1), // CNVI_RF_RST#
	// GPP_F5 (XTAL_CLKREQ) configured by FSP
	PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1), // CNVI_GNSS_PA_BLANKING
	PAD_CFG_GPO(GPP_F7, 1, DEEP), // LAN_PLT_RST#
	PAD_CFG_GPO(GPP_F8, 1, DEEP),
	PAD_CFG_GPO(GPP_F9, 1, DEEP),
	PAD_CFG_GPO(GPP_F10, 0, DEEP), // GPP_F10
	PAD_CFG_GPO(GPP_F11, 1, DEEP),
	PAD_CFG_GPI(GPP_F12, NONE, DEEP), // GPIO4_GC6_NVVDD_EN_R
	PAD_CFG_GPI(GPP_F13, NONE, DEEP), // GC6_FB_EN_PCH
	PAD_CFG_GPO(GPP_F14, 1, DEEP),
	PAD_CFG_GPO(GPP_F15, 1, DEEP),
	PAD_CFG_GPI(GPP_F16, NONE, PLTRST), // GPU_EVENT#
	PAD_CFG_GPO(GPP_F17, 1, DEEP),
	PAD_CFG_GPO(GPP_F18, 1, DEEP),
	// GPP_F19 (LAN_CLKREQ#) configured by FSP
	PAD_CFG_GPO(GPP_F20, 1, PLTRST), // M2_SSD2_RST#
	PAD_CFG_GPO(GPP_F21, 1, DEEP),
	PAD_CFG_GPO(GPP_F22, 1, DEEP),
	PAD_CFG_GPO(GPP_F23, 1, DEEP),

	/* ------- GPIO Group GPP_H ------- */
	PAD_CFG_GPO(GPP_H0, 0, DEEP), // GPP_H0
	PAD_CFG_GPO(GPP_H1, 1, PLTRST), // M2_SSD1_RST#
	PAD_CFG_GPO(GPP_H2, 1, PLTRST), // M2_WLAN_RST#
	PAD_CFG_GPI(GPP_H3, NONE, DEEP), // TPM_DET
	PAD_CFG_NF(GPP_H4, NONE, DEEP, NF1), // I2C_SDA_TP
	PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1), // I2C_SCL_TP
	PAD_CFG_NF(GPP_H6, NONE, DEEP, NF1), // PCH_I2C_SDA
	PAD_CFG_NF(GPP_H7, NONE, DEEP, NF1), // PCH_I2C_SCL
	PAD_CFG_NF(GPP_H8, NONE, DEEP, NF2), // CNVI_MFUART2_RXD
	PAD_CFG_GPO(GPP_H9, 0, DEEP), // CNVI_MFUART2_TXD
	// GPP_H10 (UART0_RXD) configured in bootblock
	// GPP_H11 (UART0_TXD) configured in bootblock
	PAD_CFG_GPO(GPP_H12, 1, DEEP),
	PAD_CFG_GPO(GPP_H13, 1, DEEP),
	PAD_CFG_GPO(GPP_H14, 1, DEEP),
	PAD_CFG_GPO(GPP_H15, 1, DEEP),
	PAD_CFG_GPO(GPP_H16, 1, DEEP),
	PAD_CFG_GPO(GPP_H17, 1, DEEP),
	PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1), // CPU_C10_GATE#
	PAD_CFG_NF(GPP_H19, NONE, DEEP, NF1), // PEX_SSD1_CLKREQ#
	PAD_CFG_GPI(GPP_H20, NONE, DEEP),
	PAD_CFG_GPI(GPP_H21, NONE, DEEP),
	PAD_CFG_GPO(GPP_H22, 0, DEEP),
	// GPP_H23 (CARD_CLKREQ#) configured by FSP

	/* ------- GPIO Group GPP_R ------- */
	PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1), // HDA_BITCLK
	PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1), // HDA_SYNC
	PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1), // HDA_SDOUT
	PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1), // HDA_SDIN0
	PAD_CFG_NF(GPP_R4, NONE, DEEP, NF1), // HDA_RST#_R
	PAD_CFG_GPO(GPP_R5, 1, DEEP),
	PAD_CFG_GPO(GPP_R6, 1, DEEP),
	PAD_CFG_GPO(GPP_R7, 1, DEEP),

	/* ------- GPIO Group GPP_S ------- */
	PAD_CFG_GPO(GPP_S0, 1, DEEP),
	PAD_CFG_GPO(GPP_S1, 1, DEEP),
	PAD_CFG_GPO(GPP_S2, 1, DEEP),
	PAD_CFG_GPO(GPP_S3, 1, DEEP),
	PAD_CFG_GPO(GPP_S4, 1, DEEP),
	PAD_CFG_GPO(GPP_S5, 1, DEEP),
	PAD_CFG_GPO(GPP_S6, 1, DEEP),
	PAD_CFG_GPO(GPP_S7, 1, DEEP),

	/* ------- GPIO Group GPP_T ------- */
	PAD_CFG_GPO(GPP_T2, 1, DEEP),
	PAD_CFG_GPO(GPP_T3, 1, DEEP),
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
