//
//  main.cpp
//  Navigation
//
//  Created by Mathias, Keerthikan og Anders.
//

#include "Vertex.h"
#include "FileHandle.h"
#include "Graph.h"
#include "Dijkstras.h"

int main(int argc, const char * argv[]) {
	std::shared_ptr<Graph> graph(new Graph);
	clock_timer timerrecord;
	std::string fromTown;
	std::string toTown;
    std::cout<<"Departure town: ";
	std::cin>>fromTown;
	std::cout<<"Arrival town:   ";
	std::cin>>toTown;
    //////////// Question #1 ////////////
	FileHandle filehandle("../../data.raw");
	//FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");
	filehandle.doParse(graph);
	//////////// Question #2 ////////////
	graph->printFrom(fromTown);
	//////////// Question #3 ////////////
	Dijkstras di(graph);
	timerrecord.start_timer();
	DijkResult result =  di.Run(fromTown, toTown);
	timerrecord.stop_timer();
	std::cout <<"---------------------"<<std::endl;
	std::cout <<"Departure: "<< fromTown <<std::endl;
	std::cout <<"Arrival:   "<< toTown <<std::endl;
	std::cout <<"Shifts:    "<< result.Shifts <<": " << result.Path << std::endl;
	std::cout <<"Ticket:    "<< result.Ticket <<",- DKK"<<std::endl;
	std::cout <<"Duration:  "<< timerrecord.duration <<" [ms]"<<std::endl;
	std::cout <<"---------------------"<<std::endl;
	return 0;
}