/*
 * Graph.h
 *
 *  Created on: Oct 25, 2014
 *      Author: exchizz
 */


#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Vertex.h"
#include "LateXGenerator.h"
#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {
	typedef std::map <std::string, Vertex*> Vertices;
	typedef std::pair <Vertex, int> Edge;
public:
	Graph();
	std::map <std::string, Vertex*> vertices;
	void addVertex(std::string value);
	void addEdge(std::string From, std::string To, int cost);
	void printVertices();
};

#endif /* GRAPH_H_ */
