//============================================================================
// Name        : Graph_v1.cpp
// Author      : Mathias Neerup
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"


int main() {

	Graph graph;
	try {
		graph.addVertex("Odense");
		graph.addVertex("Næstved");
		graph.addVertex("Nyborg");
		graph.addVertex("København");

		graph.addEdge("Odense","Næstved",200);
		graph.addEdge("Odense","Nyborg",100);
		graph.addEdge("Nyborg","Odense",10);
		graph.addEdge("Odense","København",123);
	} catch (std::string* e) {
		std::cout << *e << std::endl;
	}

	graph.printVertices();


	//graph.addEdge("Odense", "Næstved", 200);

	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	return 0;
}
