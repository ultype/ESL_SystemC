#include "DMA.h"
#include "Memory.h"

#define 0x0001 BASE_MEM0  //0X00010000
#define 0x0001 SIZE_MEM0  //0X00010000
#define 0x0002 BASE_MEM1  //0X00020000
#define 0x0001 SIZE_MEM1  //0X00010000

void Bus::bus_ctrl() {
    
    // Master0 port
    uint32_t waddr_m0_in  = waddr_m0.read();
    uint32_t wdata_m0_in  = wdata_m0.read();
    uint32_t raddr_m0_in  = raddr_m0.read();
    //uint32_t rdata_m0_out
    bool rw_m0_in         = rw_m0.read();
    
    // Slave0 port
    //uint32_t waddr_s0_out;
    //uint32_t wdata_s0_out;
    //uint32_t raddr_s0_out;
    uint32_t rdata_s0_in = rdata_s0.read();
    //bool rw_s0_out;
    
    // Slave1 port
    //uint32_t waddr_s1_out;
    //uint32_t wdata_s1_out;
    //uint32_t raddr_s1_out;
    uint32_t rdata_s1_in = rdata_s1.read();
    //bool rw_s1_out;

    uint32_t mux_sel;

    if(rw_m0_in){  //write
        switch( (waddr_m0_in>>16) ){
            case BASE_MEM0:
                rdata_m0.write(0);

                waddr_s0.write(waddr_m0_in);
                wdata_s0.write(wdata_m0_in);
                
                raddr_s0.write(0)
                rw_s0.write(1);

                waddr_s1.write(0);
                wdata_s1.write(0);
                
                raddr_s1.write(0);
                rw_s1.write(0);
                break;
            case BASE_MEM1:
                rdata_m0.write(0);

                waddr_s0.write(0);
                wdata_s0.write(0);
                
                raddr_s0.write(0);
                rw_s0.write(0);

                waddr_s1.write(waddr_m0_in);
                wdata_s1.write(wdata_m0_in);
                
                raddr_s1.write(0);
                rw_s1.write(1);
                break;
            default :
                rdata_m0.write(0);

                waddr_s0.write(0);
                wdata_s0.write(0);
                
                raddr_s0.write(0)
                rw_s0.write(0);

                waddr_s1.write(0);
                wdata_s1.write(0);
                
                raddr_s1.write(0);
                rw_s1.write(0);
                break;
        }
    }else{        //read
        switch( (raddr_m0_in>>16) ){
            case BASE_MEM0:
                rdata_m0.write(rdata_s0_in);

                waddr_s0.write(0);
                wdata_s0.write(0);

                raddr_s0.write(raddr_m0_in)
                rw_s0.write(0);

                waddr_s1.write(0);
                wdata_s1.write(0);
                
                raddr_s1.write(0);
                rw_s1.write(0);
                break;
            case BASE_MEM1:
                rdata_m0.write(rdata_s1_in);

                waddr_s0.write(0);
                wdata_s0.write(0);

                raddr_s0.write(0)
                rw_s0.write(0);

                waddr_s1.write(0);
                wdata_s1.write(0);
                
                raddr_s1.write(raddr_m0_in);
                rw_s1.write(0);
                break;
            default :
                rdata_m0.write(0);

                waddr_s0.write(0);
                wdata_s0.write(0);
                
                raddr_s0.write(0)
                rw_s0.write(0);

                waddr_s1.write(0);
                wdata_s1.write(0);
                
                raddr_s1.write(0);
                rw_s1.write(0);
                break;
        }
    }
}
