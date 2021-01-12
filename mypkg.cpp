#include <iostream>
#include "mypkg.h"
#include <zlib.h>

void mypkg(){
    z_stream defstream;
    #ifdef NDEBUG
    std::cout << "mypkg/1.0: Hello World Release!" <<std::endl;
    #else
    std::cout << "mypkg/1.0: Hello World Debug!" <<std::endl;
    #endif
}
