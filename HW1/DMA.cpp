#include "DMA.h"
#include "Memory.h"

void dma::cputodma() {
    
    for (int i = 0 ; i < 4 ; i++){
        control_register[i].write(0)  ;
    }
    state_register.write(0)  ;
    data_register.write(0) ;
    offset.write(0) ;
    interrupt.write(0) ;
    base_address.write(BASE_ADDRESS) ;
    
    wait() ;

    while(1){
        if (control_register[3].read() == 1){   //Start = 1 
            if (control_register[2].read() > 0){   //Size > 0
                if (state_register.read() == 0){   //state 0 : read source_address
                    //cout << "state_register : " << state_register.read() << endl; 
                    if(control_register[2].read() >= 4){
                        master_address.write(control_register[0].read() + offset.read()) ;
                    }
                    else {
                        master_address.write(control_register[0].read() + control_register[2].read()) ;
                    }
                    master_data_write.write(0) ;
                    read_or_write.write(0) ;
                    state_register.write(1) ; 
                }
                else if (state_register.read() == 1){  //state 1 : waiting for memory process
                    //cout << "master_data_register : " << master_data_read.read() << endl ;                    
                    state_register.write(2) ;  
                    //cout << "state_register : " << state_register.read() << endl; 
                }
                else if (state_register.read() == 2){   //state 2 : read from memory
                    //cout << "state_register : " << state_register.read() << endl ;  
                    //cout << "master_data_register : " << master_data_read.read() << endl ;
                    data_register.write( master_data_read.read() ) ;
                    state_register.write(3) ;
                }
                else if (state_register.read() == 3) {  //state 3 : read target_address & send data to target 
                    //cout << "state_register : " << state_register.read() << endl ; 
                    if(control_register[2].read() >= 4){
                        master_address.write(control_register[1].read() + offset.read()) ;
                        offset.write(offset.read() + 4) ;
                        control_register[2].write(control_register[2].read() - 4) ;
                    }
                    else {
                        master_address.write(control_register[1].read() + control_register[2].read());
                        control_register[2].write(control_register[2].read() - control_register[2].read()) ;
                    }
                    master_data_write.write(data_register.read()) ;
                     //cout << "data_register : " << data_register.read() << endl ;  
                    read_or_write.write(1) ;
                    state_register.write(0) ;  

                }
            }
            else if(control_register[2].read() == 0){
                interrupt.write(1) ;
                control_register[3].write(0) ;
            }
            
        }
        else if (clear.read() && interrupt.read()){
            for (int i = 0 ; i < 4 ; i++){
                control_register[i].write(0)  ;
            }           
            offset.write(0) ;
            data_register.write(0) ;
            interrupt.write(0) ;
        }
        else if (clear.read() == 0 ){
            switch(slave_address.read() - base_address.read()){
                case(0x0) :
                    control_register[0].write(slave_data.read()) ;
                case(0x4) :
                    control_register[1].write(slave_data.read()) ;
                case(0x8) :
                    control_register[2].write(slave_data.read()) ;
                case(0xc) :
                    control_register[3].write(slave_data.read()) ;
            }
        }
    wait() ; 
    }
   
}
