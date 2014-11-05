#include "Graph.h"

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

	from->edge.push(std::make_pair(to,Cost));
}


void Graph::printFrom(std::string from){
	if(vertices.find(from) == vertices.end()){
		std::cout <<  "City \"" + from +  "\" not found" << std::endl;
		return ;
	}
	for(auto it = vertices[from]->edge.get_container().begin() ; it != vertices[from]->edge.get_container().end(); ++it ){
		std::cout << "To: " << it->first->element << " Cost: " <<it->second  << std::endl;
	}
}