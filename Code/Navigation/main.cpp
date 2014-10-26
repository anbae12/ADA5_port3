//
//  main.cpp
//  Navigation
//
//  Created by Mathias, Kiddi og Anders.
//

#include "clock_timer.h"
#include "Vertex.h"
#include "FileHandle.h"
#include "Graph.h"
#include <fstream>

int main(int argc, const char * argv[]) {
	clock_timer timerrecord;
	timerrecord.start_timer();

	FileHandle filehandle("../../data.raw");

	Graph graph;
	filehandle.doParse(graph);

	std::ofstream myfile;
	myfile.open ("example.txt");
	myfile << graph.printVertices();
	myfile.close();

	std::ofstream myfile2;
	myfile2.open ("from-graph.txt");
	myfile2 << graph.printFrom("Nysted");
	myfile2.close();
	/*
	for(auto i = vertices.begin(); i != vertices.end(); ++i){
		std::cout <<  "from: " << (*i).from << "\tcity: " << (*i).to << "\tcost: " << (*i).cost << std::endl;
		graph.addVertex(i->from);
	}
	 */
	std::cout << "Hello, World!\n";
	timerrecord.stop_timer();

	return 0;
}
