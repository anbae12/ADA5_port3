//
//  main.cpp
//  port4
//
//  Created by Anders Launer Bæk on 14/11/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>    // std::binary_search, std::sort
#include <queue>
#include "clock_timer.h"



std::vector<int> list;
std::vector<std::pair<int, int>> hitsVector;
std::deque<std::pair<int, int>> dataVector;
int hits=0;


void make_list(int maxElements, int maxNumber, std::vector<int> &list){
    for (int i=0; i<maxElements; i++) {
        list.push_back(std::rand()%maxNumber);
    }
}
void print_list(){
    while(!list.empty()) {
        std::cout<<list.back() <<std::endl;
        list.pop_back();
    }
}

void find_match(std::vector<int> &a){
    for (int i=0; i<a.size(); i++) {
        for (int j=i+1; j<a.size(); j++) {
            if (a[i]+a[j]==10) {
                hitsVector.push_back(std::make_pair(i, j));
                hits++;
            }
         }
     }
    
}

void print(std::vector<int>&a){
    for (int i=0; i<a.size() ; i++) {
        std::cout<<a[i]<<" ";
    }
    std::cout<<""<<std::endl;
}


void binary(int sum, std::vector<int> &list)
{
    int find_value = 0;
    int hits = 0;
    for (int i = 0; i<list.size(); i++) {
        find_value = 10 - list[i];
        
        if(std::binary_search(list.begin(),list.end(),find_value)){
            cout << "bool - test" << endl;
            std::cout << find_value<<" found" << std::endl;
            hits++;
        }
        
        else
            std::cout << find_value << " Not found" << std::endl;
        
    }
    
    cout << "hits - counter " << hits << endl;
}

int main() {
    
    for (int i=1000; i<=10000; i+=1000) {
        clock_timer timer;
        timer.start_timer();
        make_list(i,10,list);
        find_match(list);
        timer.stop_timer();
        dataVector.push_back(std::make_pair(i, timer.duration));
        //std::cout << "Number of hits: "<<hits<<std::endl;
        hits=0;
    }
    

    while(!dataVector.empty()) {
        //std::cout<<"N: "<<dataVector.front().first <<"[ms]: "<<dataVector.front().second <<std::endl;
        std::cout<<dataVector.front().first <<" , "<<dataVector.front().second <<std::endl;
        
        dataVector.pop_front();
    }
    
    
    
    return 0;
}
