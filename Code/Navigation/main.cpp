//
//  main.cpp
//  Navigation
//
//  Created by Mathias, Keerthikan og Anders.
//

#include "Vertex.h"
#include "FileHandle.h"
#include "Graph.h"
#include "dijkstras.h"
#include <fstream>
#include <queue>
#include <vector>



int main() {

	//Create graph
    Graph graph;
    
    //////////// Question #1 ////////////
    //FileHandle filehandle("../../data.raw");
    FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");
	filehandle.doParse(graph);
	
    //////////// Question #2 ////////////
    //graph.printFrom("Allinge");
    
    
    //////////// Question #3 ////////////
    //Tid mangler / path;
    dijkstras di("Aalborg","København", graph);

    
    // path di.path(graph.vertices["A"] ,graph.vertices["E"]);
    
    

	return 0;
}
