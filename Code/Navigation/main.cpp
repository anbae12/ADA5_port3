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
#include <queue>
#include <vector>



int main(int argc, const char * argv[]) {

	clock_timer timerrecord;
    Graph graph;
	timerrecord.start_timer();
    
	
    FileHandle filehandle("../../data.raw");
   // FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");

	
	filehandle.doParse(graph);

	std::ofstream myfile;
	myfile.open ("example.txt");
	myfile << graph.printVertices();
	myfile.close();
/*
	std::ofstream myfile2;
	myfile2.open ("from-graph.txt");
	myfile2 << graph.printFrom("Nysted");
	myfile2.close();
	
	for(auto i = vertices.begin(); i != vertices.end(); ++i){
		std::cout <<  "from: " << (*i).from << "\tcity: " << (*i).to << "\tcost: " << (*i).cost << std::endl;
		graph.addVertex(i->from);
	}
 
 */
    
   
    /*
    std::cout<<"#2to: "<< graph.pq.top().first<<" pris: "<<graph.pq.top().second<<std::endl;
    graph.pq.pop();
    graph.vertices.find("Nysted")->second.pop();
    graph.printFrom("Nysted");
    */
	std::cout << "output: " << graph.vertices["Odense"]->edge.top().first->element;
	std::cout << "output: " << graph.vertices["Odense"]->edge.top().second << std::endl;
	graph.vertices["Odense"]->edge.pop();
	std::cout << "output: " << graph.vertices["Odense"]->edge.top().first->element;
	std::cout << "output: " << graph.vertices["Odense"]->edge.top().second << std::endl;
	std::cout << "Hello, World!\n";
	timerrecord.stop_timer();

	return 0;
}
