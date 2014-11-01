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




int main(int argc, const char * argv[]) {
    Graph graph;
    std::string toto;
    std::string fromfrom;
    std::cout<<"Departure town: ";
    std::cin>>fromfrom;
    std::cout<<"Arrival town:   ";
    std::cin>>toto;
    
    
//////////// Question #1 ////////////
    //FileHandle filehandle("../../data.raw");
    FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");
	filehandle.doParse(graph);
//////////// Question #2 ////////////
    graph.printFrom(fromfrom);
//////////// Question #3 ////////////
    //Tid mangler / path;
    dijkstras di(fromfrom,toto, graph);
    return 0;
}
