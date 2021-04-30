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

#define DATA0			0x04
#define DATA1			0x05
#define DATA2			0x06
#define DATA3			0x07
#define DATA4			0x08
#define DATA5			0x09
#define DATA6			0x0a
#define DATA7			0x0b
#define DATA8			0x0c
#define DATA9			0x0d
#define DATA10			0x0e
#define DATA11			0x0f
#define DMCONTROL		0x10
#define DMSTATUS		0x11
#define HARTINFO		0x12
#define HALTSUM1		0x13
#define HAWINDOWSEL		0x14
#define HAWINDOW		0x15
#define ABSTRACTCS		0x16
#define COMMAND			0x17
#define ABSTRACTAUTO	0x18
#define CONFSTRPTR0		0x19
#define CONFSTRPTR1		0x1a
#define CONFSTRPTR2		0x1b
#define CONFSTRPTR3		0x1c
#define NEXTDM			0x1d
#define CUSTOM			0x1f
#define PROGBUF0		0x20
#define PROGBUF1		0x21
#define PROGBUF2		0x22
#define PROGBUF3		0x23
#define PROGBUF4		0x24
#define PROGBUF5		0x25
#define PROGBUF6		0x26
#define PROGBUF7		0x27
#define PROGBUF8		0x28
#define PROGBUF9		0x29
#define PROGBUF10		0x2a
#define PROGBUF11		0x2b
#define PROGBUF12		0x2c
#define PROGBUF13		0x2d
#define PROGBUF14		0x2e
#define PROGBUF15		0x2f
#define AUTHDATA		0x30
/* empty 0x31 */
#define DMCS2			0x32
/* empty 0x33 */
#define HALTSUM2		0x34
#define HALTSUM3		0x35
/* empty 0x36 */
#define SBADDRESS3		0x37
#define SBCS			0x38
#define SBADDRESS0		0x39
#define SBADDRESS1		0x3a
#define SBADDRESS2		0x3b
#define	SBDATA0			0x3c
#define	SBDATA1			0x3d
#define	SBDATA2			0x3e
#define	SBDATA3			0x3f
#define HALTSUM0		0x40
/* empty 0x41 ~ 0x6f */
#define CUSTOM0			0x70
#define CUSTOM1			0x71
#define CUSTOM2			0x72
#define CUSTOM3			0x73
#define CUSTOM4			0x74
#define CUSTOM5			0x75
#define CUSTOM6			0x76
#define CUSTOM7			0x77
#define CUSTOM8			0x78
#define CUSTOM9			0x79
#define CUSTOM10		0x7a
#define CUSTOM11		0x7b
#define CUSTOM12		0x7c
#define CUSTOM13		0x7d
#define CUSTOM14		0x7e
#define CUSTOM15		0x7f

/* Read-only */
struct dmstatus_t {
	/* Hardwired to zero */
	zero0[7];
	/* `udmresetpending`
		0: Unimplemented, or `ndmreset` is zero and no ndmreset is currently in progress.
		1: `ndmreset` is currently nonzero, or there is an ndmreset in progress.
	*/
	ndmresetpending[1];
	/* `stickyunavail`
		0: The per-hart unavail bits reflect the current state of the hart.
		1: The per-hart unavail bits are sticky. Once they are set, they will not clear
			until the debugger acknowleges them using `ackunavail`.
	*/
	stickyunavail[1];
	/* `impebreak`
		1: There is an implict `ebreak` instruction at the non-existent word immediately after
			the Program Buffer. This saves the debugger from having to write the `ebreak` itself,
			and allows the Program Buffer to be one word smaller.
		This must be 1 when `progbufsize` is 1.
	*/
	impebreak[1];
	/* Hardwired to zero */
	zero1[2];
	/* `allhavereset`
		1: All currently selected harts have been reset and reset has not been acknowleged
			for any of them.
	*/
	allhavereset[1];
	/* `anyhavereset`
		1: At least one currently selected harts have been reset and reset has not been acknowleged
			for that hart.
	*/
	anyhavereset[1];
	/* `allresumeack`
		1: All currently selected harts have acknowleged their last resume request.
	*/
	allresumeack[1];
	/* `anyresumeack`
		1: Any currently selected hart has acknowleged its last resume request.
	*/
	anyresumeack[1];
	allnonexistent[1];
	anynonexistent[1];
	allunavail[1];
	anyunavail[1];
	allrunning[1];
	anyrunning[1];
	allhalted[1];
	anyhalted[1];
	authenticated[1];
	authbusy[1];
	hasresethaltreq[1];
	confstrptrvalid[1];
	version[4];
};

#endif
