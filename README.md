## riscv-debug

### About this project
- Implementation of RISC-V Debug spec(ver1.3)
### Target platform
- [rv32xsoc](https://github.com/koyamanX/rv32x_dev) on DE10-Lite
- Debug transport used in this project is Intel FPGA Virtual JTAG
- riscv-openocd directory contains VJTAG supports

### TODO
- [ ] Give the debugger necessary information about the implementation
- [ ] Allow any individual hart to be halted and resumed
- [ ] Provide status on which harts are halted
- [ ] Provide abstract read and write access to a halted hart's GPRs
- [ ] Provide access to reset signal that allows debugging from the very first instruction after reset

- [ ] Implement program buffer
- [ ] Implement abstarct access to all registers that are visible to software running on the hart including all the registers that are present on the hart and listed in Table 3.3 in debug-spec
- [ ] Implement abstract access to at least all GPRs, dcsr, and dpc
