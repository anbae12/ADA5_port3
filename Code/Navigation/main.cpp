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
#include <memory>

int main(int argc, const char * argv[]) {
    Graph graph;

    std::string toTown;
    std::string fromTown;
    std::cout<<"Departure town: ";
    std::cin>>fromTown;
    std::cout<<"Arrival town:   ";
    std::cin>>toTown;
//////////// Question #1 ////////////
    FileHandle filehandle("../../data.raw");
    //FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");
	filehandle.doParse(graph);
//////////// Question #2 ////////////
    graph.printFrom(fromTown);
//////////// Question #3 ////////////
    //Tid mangler / path;
    dijkstras di(fromTown,toTown, graph);
    return 0;
}
