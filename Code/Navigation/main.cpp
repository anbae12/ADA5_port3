//
//  main.cpp
//  Navigation
//
//  Created by Mathias, Kiddi og Anders.
//

#include <iostream>
#include "clock_timer.h"
int main(int argc, const char * argv[]) {
    clock_timer timerrecord;
    timerrecord.start_timer();
    std::cout << "Hello, World z!\n";
    timerrecord.stop_timer();

    return 0;
}
