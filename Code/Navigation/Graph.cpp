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

std::string Graph::printVertices(){
	LateXGenerator lateXGenerator;
	int m = 0;
/*
	for(Vertices::iterator i = vertices.begin(); i != vertices.end() && m++ < 100; ++i){
		lateXGenerator.AddVertex(i->first);
		std::cout << "Edge from: " <<  i->first;
		for(std::vector<std::pair <Vertex*, int> >::iterator j = i->second->edge.begin(); j != i->second->edge.end() ; ++j ){
			std::cout << "\t" << j->first->element << " price: " << j->second <<  std::endl;
			lateXGenerator.AddEdge(i->first,j->first->element, j->second);
		}
		std::cout << std::endl;
	}
	*/
	return lateXGenerator.getOutput();
}


std::string Graph::printFromDot(std::string from){
	LateXGenerator lateXGenerator;
	Vertex * fromP = vertices.find(from)->second;

	lateXGenerator.AddVertex(from);
        for(auto it = vertices[from]->edge.get_container().begin() ; it != vertices[from]->edge.get_container().end(); ++it ){
            std::cout << "From \"" + from + "\" to: " << it->first->element << std::endl;
            lateXGenerator.AddEdge(from,it->first->element, it->second);
        }
	return lateXGenerator.getOutput();
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
