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
		fin.seekg (1, std::ios::cur); // Ignore starting { in line
		getline(fin, line);

		std::stringstream lineStream(line);
		std::string city, cost;

		std::string from = getFrom(lineStream);

		while(std::getline(lineStream,city,',') && std::getline(lineStream,cost,',')){
			//Remove leading and trailing whitespaces.(by ref)
			trim(city);

			//convert to integer
			int iCost;
			std::istringstream ( cost ) >>  iCost;

			//Create object and push to vector - this might be priority_queue later
			vertices.push_back(Vertex(from, city, iCost));
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
std::string FileHandle::getFrom(std::stringstream &stream){
	std::string from;
	std::getline(stream,from,',');

	return from;
}


void FileHandle::trim(std::string &s){
	s = ltrim(rtrim(s));
}



