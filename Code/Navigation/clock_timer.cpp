//
//  clock_timer.cpp
//  timer_clock
//
//  Created by Anders Launer Bæk on 12/09/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

#include "clock_timer.h"
#include <time.h>


void clock_timer::start_timer(){
    clock_t temp_clock;
    temp_clock=clock();
}

float clock_timer::stop_timer(){
    temp_clock = clock()-temp_clock;
    time=(((float)temp_clock)/CLOCKS_PER_SEC)*1000;
    //std::cout<< "Time: "<<time<<"[ms]"<< std::endl;
    return time;
}
