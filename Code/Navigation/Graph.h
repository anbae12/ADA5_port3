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
#include <queue>
#ifndef GRAPH_H_
#define GRAPH_H_

struct Comp{
    bool operator()(const std::pair<Vertex*, int> &a ,const std::pair<Vertex*, int> &b ) const {
        return b.second < a.second;
    }
};

//using pqueue = std::priority_queue<std::pair<Vertex*, int>, std::vector<std::pair<Vertex*, int> >, Comp>;

using pqueue = std::priority_queue<std::pair<Vertex*, int>, std::vector<std::pair<Vertex*, int> >, Comp>;

class Graph {
	typedef std::map <std::string, Vertex*> Vertices;
	typedef std::pair <Vertex, int> Edge;
//    std::priority_queue< VertexTemp, std::vector<VertexTemp>, Comp> pq;
    
    

public:
    
    //std::priority_queue<std::pair<Vertex*, int>, std::vector<Vertex*, int> >, MyComparator> queue;
	Graph();
	std::map <std::string, Vertex*> vertices;
	void addVertex(std::string value);
	void addEdge(std::string From, std::string To, int cost);
	std::string printVertices();
	std::string printFrom(std::string from);
    //void addToQueue(std::string From, std::string To, int cost);
    pqueue pq;
    bool printException;
    
};

#endif /* GRAPH_H_ */
