//
//  clock_timer.h
//
//  Created by Anders Launer Bæk on 12/09/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

/*
 remember to include header: 
 #include "clock_timer.h"
 
 Useage:
 
 clock_timer timerrecord;
 timerrecord.start_timer();
 timerrecord.stop_timer();
 */

#ifndef __timer_clock__clock_timer__
#define __timer_clock__clock_timer__
#include <time.h>
#include <iostream>
class clock_timer{
public:
    void start_timer(void );
    void stop_timer(void );
protected:
    float time;
    long double temp_clock;
    
private:
    


};



#endif /* defined(__timer_clock__clock_timer__) */
