/*
 * FileHandle.h
 *
 *  Created on: Oct 24, 2014
 *      Author: exchizz
 */

#ifndef FILEHANDLE_H_
#define FILEHANDLE_H_
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Vertex.h"
#include "Graph.h"

class VertexTemp {
public:
	VertexTemp(std::string From, std::string To, int cost);
	std::string from;
	std::string to;
	int cost;
};
class FileHandle {
public:
	FileHandle(std::string filename);
    std::vector<VertexTemp> doParse(Graph &graph);
	std::string rtrim(std::string s);
	std::string ltrim(std::string s);
	std::string getFrom(std::stringstream &stream);
	void trim(std::string &);
	std::string to, cost;
private:
	std::string line;
	std::vector<VertexTemp> vertices;
	std::ifstream fin;
};



#endif /* FILEHANDLE_H_ */
