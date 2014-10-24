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

class FileHandle {
public:
	FileHandle(std::string filename);
	std::vector<Vertex> doParse();
	std::string rtrim(std::string s);
	std::string ltrim(std::string s);
	std::string getFrom(std::stringstream &stream);
	void trim(std::string &);
private:
	std::string line;
	std::vector<Vertex> vertices;
	std::ifstream fin;
};

#endif /* FILEHANDLE_H_ */
