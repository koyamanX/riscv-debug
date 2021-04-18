#ifndef DTM_H
#define DTM_H

/* This module design to run in TCK in JTAG clock domain */
/* m_clock must be connected to TCK of JTAG */

#define IDCODE		5'b00001
#define DTMCS		5'b10000
#define BYPASS		5'b00000

#define DTMCS_VERSION	4'b0001
#define DTMCS_ABITS		6'b011111

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

#ifdef DEBUG
	output debug_out[32];
#endif
}

#endif
