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
#include "Matcher.h"
#include <fstream>


std::vector<int> list;
std::vector<std::pair<int, int>> hitsVector;
std::deque<std::pair<int, int>> dataVector;

int main() {
	Matcher match;
	for (int i=1000; i<=100000; i+=1000) {
		clock_timer timer;
		list.clear();
		for(int j = 0; j <= i; ++j){
			list.push_back(j);
		}
		timer.start_timer();
		int hits2 = match.nSquare(i*2+1, list);
		//int hits2 = match.nLogn(i*2+1, list);
		timer.stop_timer();
		dataVector.push_back(std::make_pair(i, timer.duration));
		std::cout << "found: " << hits2 << std::endl;
	}


	std::ofstream myfile;
	myfile.open("B.txt");

	while(!dataVector.empty()) {
		std::cout<<dataVector.front().first <<" , "<<dataVector.front().second <<std::endl;
		myfile<< dataVector.front().first << "\t" << dataVector.front().second << "\n";
		dataVector.pop_front();
	}
	myfile.close();

	std::cout << "Hello world\n";


	return 0;
}

