#include "systemc.h"

#define ADDR_WIDTH 32
#define DATA_WIDTH 32
#define BASE_MEM0  0x0000 //0X00000000
#define SIZE_MEM0  0x0001 //0X00010000
#define BASE_MEM1  0x0001 //0X00010000
#define SIZE_MEM1  0x0001 //0X00010000

SC_MODULE (Bus) {

    // port
    sc_in<bool> clock ;
    sc_in<bool> rst ;
    
    // Master0 port
    sc_in<sc_uint<ADDR_WIDTH> > waddr_m0;
    sc_in<sc_uint<DATA_WIDTH> > wdata_m0;
    sc_in<sc_uint<ADDR_WIDTH> > raddr_m0;
    sc_out<sc_uint<DATA_WIDTH> > rdata_m0;
    sc_in<bool> rw_m0;
    
    // Slave0 port
    sc_out<sc_uint<ADDR_WIDTH> > waddr_s0;
    sc_out<sc_uint<DATA_WIDTH> > wdata_s0;
    sc_out<sc_uint<ADDR_WIDTH> > raddr_s0;
    sc_in<sc_uint<DATA_WIDTH> > rdata_s0;
    sc_out<bool> rw_s0;
    
    // Slave1 port
    sc_out<sc_uint<ADDR_WIDTH> > waddr_s1;
    sc_out<sc_uint<DATA_WIDTH> > wdata_s1;
    sc_out<sc_uint<ADDR_WIDTH> > raddr_s1;
    sc_in<sc_uint<DATA_WIDTH> > rdata_s1;
    sc_out<bool> rw_s1;

    //function
    void bus_ctrl() ;
    
    SC_CTOR (Bus){
        SC_CTHREAD (bus_ctrl, clock.pos() ) ;
        reset_signal_is(rst, true) ;
    }    
};
