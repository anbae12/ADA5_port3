#include "FileHandle.h"

FileHandle::FileHandle(std::string filename) {
	printException = false;
	fin.open(filename);
	if (!fin.good()){
		std::cout << "Unable to open file";
		exit(0);
	}
}

void FileHandle::doParse(Graph &graph){
	while(fin.peek() != -1){
		// Ignore starting { in line
		fin.seekg (1, std::ios::cur);

		//Get next line
		getline(fin, line);

		std::stringstream lineStream(line);

		std::string from = getFrom(lineStream);
		//Add vertex, else catch exception
		try {
			graph.addVertex(from);
		} catch (std::string *e){
			if(printException){
				std::cout << "exception: " << *e << std::endl;
			}
		}

		while(std::getline(lineStream,to,',') && std::getline(lineStream,cost,',')){
			//Remove leading and trailing whitespaces.
			trim(to);

			//Convert to integer
			int iCost;
			std::istringstream ( cost ) >>  iCost;

			//Add vertex if not existing, else catch exception
			try {
				graph.addVertex(to);
			} catch (std::string *e){
				if(printException){
					std::cout << "exception: " << *e << std::endl;
				}
			}
			//Add edge
			graph.addEdge(from, to, iCost);
		}
	}
}
//Trim left side of string
std::string FileHandle::ltrim(std::string s){
	s.erase(s.begin(),find_if_not(s.begin(),s.end(),[](int c){return isspace(c);}));
	return s;
}
//Trim right side of string
std::string FileHandle::rtrim(std::string s){
	s.erase(find_if_not(s.rbegin(),s.rend(),[](int c){return isspace(c);}).base(), s.end());
	return s;
}
//Trim right and left
void FileHandle::trim(std::string &s){
	s = ltrim(rtrim(s));
}
//Extracts "from", from the line
std::string FileHandle::getFrom(std::stringstream &stream){
	std::string from;
	std::getline(stream,from,',');
	return from;
}
