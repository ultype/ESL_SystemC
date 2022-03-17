#include "DMA.h"
#include "systemc.h"
#include "Memory.h"
#include "Bus.h"

#define ADDR_WIDTH 32
#define DATA_WIDTH 32
#define CONTROl_REGISTER_DEPTH 4 

//input
#define SOURCE_ADDR 8
#define TARGET_ADDR 4
#define SIZE 8 //Address width = 4 byte = 2^2 byte
#define START 1

int sc_main (int argc, char* argv[]) {
    
    sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated",
                                           sc_core::SC_DO_NOTHING );
    sc_time  period (10, SC_NS);
    sc_clock CLOCK ("clock", period);
    /*
    sc_signal<bool> RST ;
  //DMA
    sc_signal<sc_uint<ADDR_WIDTH> > SLAVE_ADDRESS ;
    sc_signal<sc_uint<DATA_WIDTH> > SLAVE_DATA ;
    sc_signal<sc_uint<DATA_WIDTH> > MASTER_DATA_READ ;

    sc_signal<bool> CLEAR ;

    sc_signal<sc_uint<ADDR_WIDTH> > MASTER_ADDRESS ;
    sc_signal<sc_uint<DATA_WIDTH> > MASTER_DATA_WRITE ;

    sc_signal<bool> INTERRUPT ;
    sc_signal<bool> READ_OR_WRITE ; 
  //memory 
    //sc_signal<sc_uint<ADDR_WIDTH> > MEMORY_ADDRESS;
    sc_signal<sc_uint<DATA_WIDTH> > WRITE_DATA;

    //sc_signal<bool> MEMORY_READ_OR_WRITE ;
    
    sc_signal<sc_uint<DATA_WIDTH> > READ_DATA;

    dma dma ("dma");
    dma.clock(CLOCK) ;
    dma.rst(RST) ;
    dma.slave_address(SLAVE_ADDRESS) ;
    dma.slave_data(SLAVE_DATA) ; 
    dma.master_data_read(MASTER_DATA_READ) ;
    dma.clear(CLEAR) ;
    dma.master_address(MASTER_ADDRESS) ;
    dma.master_data_write(MASTER_DATA_WRITE) ;
    dma.interrupt(INTERRUPT) ;
    dma.read_or_write(READ_OR_WRITE) ;

    memory memory ("memory");
    memory.clock(CLOCK) ; 
    memory.memory_address(MASTER_ADDRESS) ;
    memory.write_data(MASTER_DATA_WRITE) ;
    memory.memory_read_or_write(READ_OR_WRITE) ;
    memory.read_data(MASTER_DATA_READ) ;

	  // For in/out port 
    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, CLOCK, "clk");
    sc_trace(tf, RST, "rst");
    sc_trace(tf, CLEAR, "clear");
    sc_trace(tf, INTERRUPT, "interrupt");
    sc_trace(tf, MASTER_ADDRESS, "master_addr");
    sc_trace(tf, MASTER_DATA_READ, "master_data_read");
    sc_trace(tf, MASTER_DATA_WRITE, "master_data_write");
    sc_trace(tf, READ_OR_WRITE, "read_or_write");
    sc_trace(tf, SLAVE_ADDRESS, "slave_addr");
    sc_trace(tf, SLAVE_DATA, "slave_data");

    // For other reg of DMA
    sc_trace(tf, dma.state_register, "state_register");
    sc_trace(tf, dma.data_register, "data_register");
    sc_trace(tf, dma.offset, "offset");

    // For other reg of Memory
    sc_trace(tf, memory.source_register, "source_register");
    sc_trace(tf, memory.target_register, "target_register");

    //Start simulation
    
    //Reset
    RST.write(1) ;
    sc_start(10, SC_NS);
    RST.write(0) ;

    //CPU Write SOURCE ADDR to DMA
    SLAVE_DATA.write(SOURCE_ADDR);
    SLAVE_ADDRESS.write(0x0 + BASE_ADDRESS);
    sc_start(10, SC_NS);

    //CPU Write TARGET ADDR to DMA
    SLAVE_DATA.write(TARGET_ADDR);
    SLAVE_ADDRESS.write(0x4 + BASE_ADDRESS);
    sc_start(10, SC_NS);

    //CPU Write Size to DMA
    SLAVE_DATA.write(SIZE);
    SLAVE_ADDRESS.write(0x8 + BASE_ADDRESS);
    sc_start(10, SC_NS);

    //CPU Write Start to DMA
    SLAVE_DATA.write(START);
    SLAVE_ADDRESS.write(0xc + BASE_ADDRESS+ BASE_ADDRESS);
    sc_start(10, SC_NS);
  
    for(int j=0 ; j<12 ; j++){
      for (int i=0; i<4; i++){
		    cout << "control_register[" << i << "]:" << dma.control_register[i] << endl ;
	    }
      cout << "data_register :" << dma.data_register << endl ; 

      cout << "interrupt :" << INTERRUPT << endl ;     
      cout << "clear :" << CLEAR << endl ;
      cout << "master_addr:" << MASTER_ADDRESS << endl ; 
      cout << "source_register:" << MASTER_DATA_READ << endl ; 
      cout << "---------------------------------------------" << endl ;

      if(INTERRUPT == 1)
      {
        CLEAR.write(1) ; 
      }
      sc_start(10, SC_NS);
    }
    cout << "Source Address : " << SOURCE_ADDR << endl ; 
    cout << "Target Address : " << TARGET_ADDR << endl ; 
    cout << "Size  : " << SIZE << endl ; 
    cout << "Start : " << START << endl ; 
    cout << "---------------------------------------------" << endl ;           
    cout << " Source Memory     " << "  Target Memory       " << endl ; 
    cout << "0x0 |   " <<  memory.source_register[0] << "   |" << "       0x0 |   " << memory.target_register[0] << "   |"  << endl ; 
    cout << "0x4 |   " <<  memory.source_register[1] << "   |" << "       0x4 |   " << memory.target_register[1] << "   |"  << endl ; 
    cout << "0x8 |   " <<  memory.source_register[2] << "   |" << "       0x8 |   " << memory.target_register[2] << "   |"  << endl ; 
    cout << "0xc |   " <<  memory.source_register[3] << "   |" << "       0xc |   " << memory.target_register[3] << "   |"  << endl ; 

    sc_close_vcd_trace_file(tf);
    */
    return (0) ;
}
