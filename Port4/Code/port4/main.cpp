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
#include <fstream>


std::vector<int> list;
std::vector<std::pair<int, int>> hitsVector;
std::deque<std::pair<int, int>> dataVector;
int hits=0;


void make_list(int maxElements, int maxNumber, std::vector<int> &list){
    list.clear();
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
                //hitsVector.push_back(std::make_pair(i, j));
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
            std::cout << "bool - test" << std::endl;
            std::cout << find_value<<" found" << std::endl;
            hits++;
        }
        
        else
            std::cout << find_value << " Not found" << std::endl;
        
    }
    
    std::cout << "hits - counter " << hits << std::endl;
}

int main() {
    
    for (int i=100; i<=30000; i+=600) {
        std::cout<<"new run: "<<i<<std::endl;
        clock_timer timer;
        make_list(i,10,list);
        timer.start_timer();
        find_match(list);
        timer.stop_timer();
        dataVector.push_back(std::make_pair(i, timer.duration));
        //std::cout << "Number of hits: "<<hits<<std::endl;
        hits=0;
    }
    

    
    
    std::ofstream myfile;
    myfile.open ("/Users/Anders/Documents/Robotteknologi/5. semester/ADA/Portfolio/port3/Port4/example.txt");
    //myfile.open ("Mathias/example.txt");
    //myfile.open ("Kiddi/example.txt");
    while(!dataVector.empty()) {
        myfile <<dataVector.front().first;
        myfile<< "\t";
        myfile<<dataVector.front().second<<"\n";
        dataVector.pop_front();
    }
    myfile.close();
    
    
    
    
    
    
    return 0;
}
