//
//  main.cpp
//  Navigation
//
//  Created by Mathias, Kiddi og Anders.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <queue>
#include <sstream>
#include "clock_timer.h"

std::string ltrim(std::string s){
	s.erase(s.begin(),find_if_not(s.begin(),s.end(),[](int c){return isspace(c);}));
	return s;
}
std::string rtrim(std::string s){
	s.erase(find_if_not(s.rbegin(),s.rend(),[](int c){return isspace(c);}).base(), s.end());
	return s;
}
class Vertex{
public:
	std::string from;
	int cost;
	std::string city;

	Vertex(std::string mFrom, std::string mCity, int mCost){
		from = mFrom;
		cost = mCost;
		city = mCity;
	}
	Vertex();
};

int main(int argc, const char * argv[]) {
	clock_timer timerrecord;
	timerrecord.start_timer();

	std::ifstream fin;
	fin.open("../../data.raw");


	if (!fin.good()){
		std::cout << "Unable to open file";
		return 1;
	}

	std::vector <std::string> list_with_lines;
	std::vector <std::string> words;
	std::string line;
	std::vector<Vertex> vertices;

	while(!fin.eof()){
		fin.seekg (1, std::ios::cur); // Ignore starting { in raw file
		getline(fin, line);
		list_with_lines.push_back(line);

		std::stringstream lineStream(line);
		std::string city, cost;

		std::string from = "";

		while(std::getline(lineStream,city,',')){
			city = rtrim(ltrim(city)); // rtrim = remove right space, ltrim = remove left space.
			if(from == ""){
				from = city;
				continue;
			}
			std::getline(lineStream,cost,',');

			int iCost;
			std::istringstream ( cost ) >>  iCost;
			Vertex vertex(from, city, iCost);
			vertices.push_back(vertex);
		}
	}
	for(auto i = vertices.begin(); i != vertices.end(); ++i){
		std::cout <<  "from: " << (*i).from << "\tcity: " << (*i).city << "\tcost: " << (*i).cost << std::endl;
	}
	std::cout << "Hello, World!\n";
	timerrecord.stop_timer();

	return 0;
}
