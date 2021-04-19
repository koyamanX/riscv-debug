#ifndef DM_H
#define DM_H
/* Runs in same clock domain as DTM and output to hart must be 
	synchronized to hart's clock domain */
declare dm interface {
	input p_reset;
	input m_clock;
	/* DMI */
	input addr[32];
	input wdata[32];
	output rdata[32];
	func_in read(addr);
	func_in write(addr, wdata);
	func_out ready();
#ifdef DEBUG
	output debug_out[32];
#endif
}
#endif
