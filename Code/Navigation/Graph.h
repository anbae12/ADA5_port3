#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Vertex.h"
#include "LateXGenerator.h"
#include <queue>
#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {
	typedef std::map <std::string, Vertex*> Vertices;
	//typedef std::pair <Vertex, int> Edge;
public:
	std::map <std::string, Vertex*> vertices;
	void addVertex(std::string value);
	void addEdge(std::string From, std::string To, int cost);
	std::string printFromDot(std::string from);
	void printFrom(std::string from);
};

#endif /* GRAPH_H_ */
