#include "systemc.h"

#define ADDR_WIDTH 32
#define DATA_WIDTH 32
#define MEM_DEPTH  0x4000 //4KB   1k World
 
SC_MODULE (Memory) {

    // port
    sc_in<bool> clock ;
    sc_in<bool> rw;
    sc_in<bool> rst;

    sc_in<sc_uint<ADDR_WIDTH> > waddr;
    sc_in<sc_uint<DATA_WIDTH> > wdata;

    sc_in<sc_uint<ADDR_WIDTH> > raddr;
    sc_out<sc_uint<DATA_WIDTH> > rdata;


    // Source & target memory
    sc_signal<sc_uint<DATA_WIDTH> > mem[MEM_DEPTH] ;

    //function
    void memory_ctrl();
    void memory_write(uint32_t addr, uint32_t data);
    uint32_t memory_read(uint32_t addr);
    void memory_rst();

    SC_CTOR (Memory){
        SC_CTHREAD (memory_ctrl , clock) ;
    }
};
