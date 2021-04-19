#ifndef DTM_H
#define DTM_H

/* This module design to run in TCK in JTAG clock domain */
/* m_clock must be connected to TCK of JTAG */

#define IDCODE		5'b00001
#define DTMCS		5'b10000
#define DMI			5'b10001
#define BYPASS		5'b11111

#define DTMCS_VERSION	4'b0001
#define DTMCS_ABITS		6'b100000

#define DMI_NOP			2'b00
#define DMI_READ		2'b01
#define DMI_WRITE		2'b10
#define DMI_RESERVED	2'b11

#define DMI_STAT_SUCCESS	2'b00
#define DMI_STAT_RESERVED	2'b01
#define DMI_STAT_FAILURE	2'b10
#define DMI_STAT_INPROGRESS	2'b11

struct dtmcs_t {
	zero1[14];
	dmihardreset[1];
	dmireset[1];
	zero0[1];
	idle[3];
	dmistat[2];
	abits[6];
	version[4];
};

struct dmi_t {
	addr[32];
	data[32];
	op[2];
};

declare dtm interface {
	input m_clock;
	input p_reset;

	input ir_in[5];
	output ir_out[5];
	input tdi;
	output tdo;
	func_in virtual_state_cdr;
	func_in	virtual_state_sdr;
	func_in	virtual_state_e1dr;
	func_in	virtual_state_pdr;
	func_in	virtual_state_e2dr;
	func_in	virtual_state_udr;
	func_in	virtual_state_cir;
	func_in	virtual_state_uir;

	/* DMI */
	output addr[32];
	input rdata[32];
	output wdata[32];
	func_out read(addr);
	func_out write(addr, wdata);
	func_in ready();

#ifdef DEBUG
	output debug_out[32];
#endif
}

#endif
