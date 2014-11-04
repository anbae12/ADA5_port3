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
	std::string toTown = "Aalborg";
	std::string fromTown;
/*

	std::cout<<"Departure town: ";
	std::cin>>fromTown;
	std::cout<<"Arrival town:   ";
	std::cin>>toTown;
	*/
	//////////// Question #1 ////////////
	FileHandle filehandle("../../data.raw");
	//FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");
	filehandle.doParse(graph);
	//////////// Question #2 ////////////
	//graph->printFrom(fromTown);
	//////////// Question #3 ////////////
	//Tid mangler / path;
	float runTime = 0;

	std::vector<std::string> froms = {"Odense","Næstved","Humlebæk","København","Sønderborg", "Nysted"};
	for(auto i = froms.begin(); i != froms.end(); ++i){
		std::cout << *i << std::endl;
		Dijkstras di(graph);

		timerrecord.start_timer();
		DijkResult result =  di.Run(*i, toTown);
		timerrecord.stop_timer();
		std::cout << "runtime: "  << timerrecord.duration << std::endl;
		runTime+=timerrecord.duration;
	}
	std::cout << "RunTime : " << runTime/10 << std::endl;
/*
	std::cout <<"---------------------"<<std::endl;
	std::cout <<"Departure: "<< fromTown <<std::endl;
	std::cout <<"Arrival:   "<< toTown <<std::endl;
	std::cout <<"Shifts:    "<< result.Shifts <<": " << result.Path << std::endl;
	std::cout <<"Ticket:    "<< result.Ticket <<",- DKK"<<std::endl;
	std::cout <<"Duration:  "<< result.Duration <<" [ms]"<<std::endl;
	std::cout <<"---------------------"<<std::endl;
*/
	return 0;
}
