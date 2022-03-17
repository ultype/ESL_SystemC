#include "systemc.h"
#define ADDR_WIDTH 32
#define DATA_WIDTH 32
#define SIZE_WIDTH 32
#define CONTROl_REGISTER_DEPTH 4 
#define SOURCE_REGISTER_DEPTH 32  
#define TARGET_REGISTER_DEPTH 32 
#define BASE_ADDRESS 0  

#define STATE_IDLE  0x00
#define STATE_START 0x01
#define STATE_READ  0x02
#define STATE_WRITE 0x03
#define STATE_DONE  0x04

SC_MODULE (dma) {

    // sys port
    sc_in<bool> clk;
    sc_in<bool> rst;

    // CPU->DMA
    sc_in<bool> clear;
    sc_in<bool> start;
    sc_in<sc_uint<ADDR_WIDTH>> source_addr;
    sc_in<sc_uint<ADDR_WIDTH>> target_addr;
    sc_in<sc_uint<SIZE_WIDTH>> size;

    // DMA->CPU
    sc_out<bool> interrupt;

    // DMA->BUS
    sc_out<bool> rw;
    sc_out<sc_uint<ADDR_WIDTH> > waddr;
    sc_out<sc_uint<DATA_WIDTH> > wdata;
    sc_out<sc_uint<ADDR_WIDTH> > raddr;

    // BUS->DMA
    sc_out<sc_uint<DATA_WIDTH>> rdata;

    //function
    void dma_ctrl();
    void dma_to_cpu();
    void cpu_to_dma();

    //DMA reg
    sc_uint<ADDR_WIDTH> source_addr_reg;
    sc_uint<ADDR_WIDTH> target_addr_reg;
    sc_uint<SIZE_WIDTH> size_reg;
    sc_uint<bool> start_clear_reg;



    SC_CTOR (dma){
        SC_CTHREAD (cputodma , clock.pos() ) ;
        reset_signal_is(rst, true) ;
    }    
};
