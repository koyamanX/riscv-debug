PROJECT=DE10
PROJTCL=setup_proj.tcl  
TOP=$(PROJECT).nsl

NSL2VL=nsl2vl
NSLDEFS=-DDEBUG
NSLINC=-I../src
NSLFLAGS=-O2 -neg_res $(NSLDEFS) $(NSLINC)
NSLSRC:=$(wildcard ../src/*.nsl)
NSLSRC2:=$(notdir $(NSLSRC))
VERIFILES:=$(addprefix out/, $(NSLSRC2:.nsl=.v))

Q2SH=quartus_sh
Q2PG=quartus_pgm
CABLE="USB-Blaster"
PMODE=JTAG

all: out/$(PROJECT).sof
out:
	if [ ! -d out ]; then \
		mkdir out; \
	fi
out/%.v: ../src/%.nsl out
	$(NSL2VL) $(NSLFLAGS) $< -o $@
out/$(PROJECT).v: $(TOP) out
	$(NSL2VL) $(NSLFLAGS) $< -o $@
out/$(PROJECT).qsf: out/$(PROJECT).v $(VERIFILES)
	cd out && $(Q2SH) -t ../$(PROJTCL) -project $(PROJECT) 
out/$(PROJECT).sof: out/$(PROJECT).qsf
	cd out && $(Q2SH) --flow compile $(PROJECT)
download: 
	$(Q2PG) -c $(CABLE) -m $(PMODE) -o "p;out/$(PROJECT).sof"
compile: out/$(PROJECT).sof
clean:
	rm -rf out
