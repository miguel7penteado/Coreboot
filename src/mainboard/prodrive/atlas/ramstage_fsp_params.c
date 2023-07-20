/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/ramstage.h>

#include "vpd.h"

void mainboard_silicon_init_params(FSP_S_CONFIG *params)
{
	/* Disable and lock configurable TDP */
	params->ApplyConfigTdp = 0;
	params->ConfigTdpLock = 1;

	/* Apply profile-specific settings */
	switch (get_emi_eeprom_vpd()->profile) {
	case ATLAS_PROF_REALTIME_PERFORMANCE:
		params->Cx = 0;
		params->C1e = 0;
		params->C1StateUnDemotion = 0;
		params->C1StateAutoDemotion = 0;
		params->PkgCStateUnDemotion = 0;
		params->PkgCStateLimit = 0;

		/* PCI */
		params->PchDmiAspmCtrl = 0;
		params->PsfTccEnable = 1;
		params->PchLegacyIoLowLatency = 1;
		params->OpioRecenter = 0;
		params->PsfTccEnable = 1;
		params->RenderStandby = 0;
		params->L2QosEnumerationEn = 1;
		params->EnergyEfficientPState = 0;
		params->EnergyEfficientTurbo = 0;
		params->PchS0ixAutoDemotion = 0;

		/* Disable PMC low power modes */
		params->PmcLpmS0ixSubStateEnableMask = 0;
		params->PmcV1p05PhyExtFetControlEn = 0;
		params->PmcV1p05IsExtFetControlEn = 0;
		break;
	}
}
