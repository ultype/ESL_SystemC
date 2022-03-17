#include "systemc.h"

#define ADDR_WIDTH 32
#define DATA_WIDTH 32
#define CONTROl_REGISTER_DEPTH 4 
#define SOURCE_REGISTER_DEPTH 32  
#define TARGET_REGISTER_DEPTH 32 
#define BASE_ADDRESS 0  


SC_MODULE (DMA) {

    sc_in<bool> clock ;
    sc_in<bool> rst ;
    
    
    
    //Master0 port
    
    
    
    //
    sc_in<sc_uint<ADDR_WIDTH> > slave_address ;
    sc_in<sc_uint<DATA_WIDTH> > slave_data ;

    sc_in<bool> clear ;
    
    //master_signal
    sc_in<sc_uint<DATA_WIDTH> > master_data_read ;
    sc_out<sc_uint<DATA_WIDTH> > master_data_write ;
    sc_out<sc_uint<ADDR_WIDTH> > master_address ;

    sc_out<bool> interrupt ;
    sc_out<bool> read_or_write ; //0:read , 1:write

    //internal_variable
    sc_signal<sc_uint<DATA_WIDTH> > base_address ;
    sc_signal<sc_uint<DATA_WIDTH> > control_register[CONTROl_REGISTER_DEPTH] ;
    sc_signal<sc_uint<DATA_WIDTH> > state_register ;
    sc_signal<sc_uint<DATA_WIDTH> > data_register ;
    sc_signal<sc_uint<DATA_WIDTH> > offset ;


    //function
    void cputodma() ;

    SC_CTOR (dma){
        SC_CTHREAD (cputodma , clock.pos() ) ;
        reset_signal_is(rst, true) ;
    }    
};
