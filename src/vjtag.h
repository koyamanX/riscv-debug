#ifndef VJTAG_H
#define VJTAG_H

declare vjtag interface {
	output		tdi;
	input		tdo;
	output		ir_in[5];
	input		ir_out[5];
	func_out	virtual_state_cdr;
	func_out	virtual_state_sdr;
	func_out	virtual_state_e1dr;
	func_out	virtual_state_pdr;
	func_out	virtual_state_e2dr;
	func_out	virtual_state_udr;
	func_out	virtual_state_cir;
	func_out	virtual_state_uir;
	output		tms;
	func_out	jtag_state_tlr;
	func_out	jtag_state_rti;
	func_out	jtag_state_sdrs;
	func_out	jtag_state_cdr;
	func_out	jtag_state_sdr;
	func_out	jtag_state_e1dr;
	func_out	jtag_state_pdr;
	func_out	jtag_state_e2dr;
	func_out	jtag_state_udr;
	func_out	jtag_state_sirs;
	func_out	jtag_state_cir;
	func_out	jtag_state_sir;
	func_out	jtag_state_e1ir;
	func_out	jtag_state_pir;
	func_out	jtag_state_e2ir;
	func_out	jtag_state_uir;
	output		tck;
}
#endif
