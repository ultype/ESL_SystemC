#include "Memory.h"

void Memory::memory_ctrl() 
{
    // init
    memory_rst();
    uint32_t data;
    while(1){
        if(rst.read()){
            memory_rst();
        } else if(rw.read()){ //write
            memory_write(waddr.read(), wdata.read());
        } else { //read
            data  = memory_read(raddr.read());
            rdata.write(data);
        }
        wait() ;
    }
}

void Memory::memory_write(uint32_t addr, uint32_t data)
{
    addr = addr >> 2;
    if(addr < MEM_DEPTH) mem[addr].write(data);
}


uint32_t Memory::memory_read(uint32_t addr)
{
    addr = addr >> 2;
    if(addr < MEM_DEPTH)
        return mem[addr].read();
    else
        return 0;
}   

void Memory::memory_rst()
{
    int i;
    for (i = 0; i < MEM_DEPTH ;i++){
        memory_write(i, 0);
    }
}