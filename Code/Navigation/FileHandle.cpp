/*
 * FileHandle.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: exchizz
 */

#include "FileHandle.h"

FileHandle::FileHandle(std::string filename) {
	fin.open(filename);
	if (!fin.good()){
		std::cout << "Unable to open file";
		exit(0);
	}
}

std::vector<Vertex> FileHandle::doParse(){
	while(!fin.eof()){
		fin.seekg (1, std::ios::cur); // Ignore starting { in raw file
		getline(fin, line);

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

	return vertices;
}

std::string FileHandle::ltrim(std::string s){
	s.erase(s.begin(),find_if_not(s.begin(),s.end(),[](int c){return isspace(c);}));
	return s;
}
std::string FileHandle::rtrim(std::string s){
	s.erase(find_if_not(s.rbegin(),s.rend(),[](int c){return isspace(c);}).base(), s.end());
	return s;
}



