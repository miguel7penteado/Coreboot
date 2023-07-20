/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef HASWELL_REGISTERS_EPBAR_H
#define HASWELL_REGISTERS_EPBAR_H

#define EPPVCCAP1	0x004	/* 32bit */
#define EPPVCCAP2	0x008	/* 32bit */

#define EPVC0RCAP	0x010	/* 32bit */
#define EPVC0RCTL	0x014	/* 32bit */
#define EPVC0RSTS	0x01a	/* 16bit */

#define EPVC1RCAP	0x01c	/* 32bit */
#define EPVC1RCTL	0x020	/* 32bit */
#define EPVC1RSTS	0x026	/* 16bit */

#define EPESD		0x044	/* 32bit */

#define EPLE1D		0x050	/* 32bit */
#define EPLE1A		0x058	/* 64bit */
#define EPLE2D		0x060	/* 32bit */
#define EPLE2A		0x068	/* 64bit */
#define EPLE3D		0x070	/* 32bit */
#define EPLE3A		0x078	/* 64bit */
#define EPLE4D		0x080	/* 32bit */
#define EPLE4A		0x088	/* 64bit */

#endif /* HASWELL_REGISTERS_EPBAR_H */
