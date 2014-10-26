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
}


void Graph::printVertices(){
	LateXGenerator lateXGenerator;

	for(Vertices::iterator i = vertices.begin(); i != vertices.end(); ++i){
		lateXGenerator.AddVertex(i->first);
		std::cout << "Edge from: " <<  i->first;
		for(std::vector<std::pair <Vertex*, int> >::iterator j = i->second->edge.begin(); j != i->second->edge.end(); ++j ){
			std::cout << "\t" << j->first->element << " price: " << j->second <<  std::endl;
			lateXGenerator.AddEdge(i->first,j->first->element, j->second);
		}
		std::cout << std::endl;
	}
	std::cout << "dot output: " << lateXGenerator.getOutput() << std::endl;
}
