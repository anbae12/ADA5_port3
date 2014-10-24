//
//  main.cpp
//  Navigation
//
//  Created by Mathias, Kiddi og Anders.
//

#include "clock_timer.h"
#include "Vertex.h"
#include "FileHandle.h"


int main(int argc, const char * argv[]) {
	clock_timer timerrecord;
	timerrecord.start_timer();

	FileHandle filehandle("../../data.raw");
	std::vector<Vertex> vertices = filehandle.doParse();

	for(auto i = vertices.begin(); i != vertices.end(); ++i){
		std::cout <<  "from: " << (*i).from << "\tcity: " << (*i).city << "\tcost: " << (*i).cost << std::endl;
	}
	std::cout << "Hello, World!\n";
	timerrecord.stop_timer();

	return 0;
}
