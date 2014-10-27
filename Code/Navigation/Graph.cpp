/*
 * Graph.cpp
 *
 *  Created on: Oct 25, 2014
 *      Author: exchizz
 */

#include "Graph.h"
Graph::Graph() {
	// TODO Auto-generated constructor stub
}

void Graph::addVertex(std::string value) {
	if(vertices.find(value) != vertices.end()){
		throw new std::string("Element \"" + value + "\" already exists!");
	}
	vertices[value] = new Vertex(value);
}

void Graph::addEdge(std::string From, std::string To, int Cost) {
	if(vertices.find(From) == vertices.end())
		throw new std::string("From \"" + From + "\" does not exist!");

	if(vertices.find(To) == vertices.end())
		throw new std::string("To \"" + To + "\" does not exist!");

	Vertex* from = vertices.find(From)->second;
	Vertex* to = vertices.find(To)->second;
	from->edge.push_back(std::make_pair(to, Cost));
    
    
    /////////////////
    // std::cout<<"#1to: "<< to<<" pris: "<<Cost<<std::endl;
    pq.push(std::make_pair(to, Cost));
    
    
}


std::string Graph::printVertices(){
	LateXGenerator lateXGenerator;
	int m = 0;

	for(Vertices::iterator i = vertices.begin(); i != vertices.end() && m++ < 100; ++i){
		lateXGenerator.AddVertex(i->first);
		std::cout << "Edge from: " <<  i->first;
		for(std::vector<std::pair <Vertex*, int> >::iterator j = i->second->edge.begin(); j != i->second->edge.end() ; ++j ){
			std::cout << "\t" << j->first->element << " price: " << j->second <<  std::endl;
			lateXGenerator.AddEdge(i->first,j->first->element, j->second);
		}
		std::cout << std::endl;
	}
	return lateXGenerator.getOutput();
}


std::string Graph::printFrom(std::string from){
	LateXGenerator lateXGenerator;
	Vertex * fromP = vertices.find(from)->second;

	lateXGenerator.AddVertex(from);

	for(auto i = fromP->edge.begin(); i != fromP->edge.end(); ++i){
		std::cout << "From \"" + from + "\" to: " << i->first->element << std::endl;
		lateXGenerator.AddEdge(from,i->first->element, i->second);
	}
	return lateXGenerator.getOutput();
}
