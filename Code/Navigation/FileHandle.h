#ifndef FILEHANDLE_H_
#define FILEHANDLE_H_
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Vertex.h"
#include "Graph.h"
#include <memory>

class FileHandle {
public:
	FileHandle(std::string filename);
    void doParse(std::shared_ptr<Graph> &graph);
	std::string rtrim(std::string s);
	std::string ltrim(std::string s);
	std::string getFrom(std::stringstream &stream);
	void trim(std::string &);
	std::string to, cost;
	bool printException;
private:
	std::string line;
	std::ifstream fin;
};

#endif /* FILEHANDLE_H_ */