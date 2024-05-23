#include <iostream>

#include "Vour.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t sim_time = 0;
int main(int argc, char **argv, char **env)
{
        Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);
        Vour *top = new Vour;
	VerilatedVcdC *m_trace = new VerilatedVcdC;
	top->trace(m_trace, 5);
	m_trace->open("waveform.vcd");
	int count = 0;  
        while (!Verilated::gotFinish() && (count < 1000))
        {
                if (top->clock)
                        std::cout << " " << top->fn << std::endl;
                top->clock ^= 1;
                top->eval();
		m_trace->dump(sim_time);
		sim_time++;
		count++;
        }
	m_trace->close();
        delete top;
        exit(0);
}
