create_clock -name "m_clock" -period 50MHz [get_ports {m_clock}]
derive_pll_clocks -create_base_clocks
derive_clock_uncertainty
