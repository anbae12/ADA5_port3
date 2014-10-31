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
#include "dijkstras.h"
#include <fstream>
#include <queue>
#include <vector>



int main(int argc, const char * argv[]) {
	clock_timer timerrecord;
    Graph graph;
    
	timerrecord.start_timer();
    
    //FileHandle filehandle("../../data.raw");
    FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");

    // question one
	filehandle.doParse(graph);
/*
	std::ofstream myfile;
	myfile.open ("example.txt");
	myfile << graph.printVertices();
	myfile.close();

	std::ofstream myfile2;
	myfile2.open ("from-graph.txt");
	myfile2 << graph.printFrom("Nysted");
	myfile2.close();
	
	for(auto i = vertices.begin(); i != vertices.end(); ++i){
		std::cout <<  "from: " << (*i).from << "\tcity: " << (*i).to << "\tcost: " << (*i).cost << std::endl;
		graph.addVertex(i->from);
	}
 */
	
    // question two
    graph.printFrom("Allinge");
    // question three
    dijkstras di("Allinge", graph);

    
    
	std::cout << "Hello, World!\n";
	timerrecord.stop_timer();

	return 0;
}
