//
//  main.cpp
//  Navigation
//
//  Created by Anders Launer Bæk on 24/10/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

#include <iostream>
#include "clock_timer.h"
int main(int argc, const char * argv[]) {
    clock_timer timerrecord;
    timerrecord.start_timer();
    std::cout << "Hello, World!\n";
    timerrecord.stop_timer();

    return 0;
}
