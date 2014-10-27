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


struct Comp{
    bool operator()(const VertexTemp& a,const VertexTemp& b){
        return b.cost<a.cost;
    }
};


int main(int argc, const char * argv[]) {
    std::priority_queue< VertexTemp, std::vector<VertexTemp>, Comp> pq;
    
	clock_timer timerrecord;
	timerrecord.start_timer();

	/*
    //FileHandle filehandle("../../data.raw");
    FileHandle filehandle("/Users/anderslaunerbaek/Documents/data.raw");
    

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
	
	for(auto i = vertices.begin(); i != vertices.end(); ++i){
		std::cout <<  "from: " << (*i).from << "\tcity: " << (*i).to << "\tcost: " << (*i).cost << std::endl;
		graph.addVertex(i->from);
	}
	 */
    
    
    
    
    
    
    pq.push(VertexTemp("Middelfart", "Odense1",200));
    pq.push(VertexTemp("Middelfart", "Odense2",210));
    pq.push(VertexTemp("Middelfart", "Odense3",22));
    
    
    VertexTemp b = pq.top();
    pq.pop();
    std::cout<<b.from<<" "<<b.to<<" "<<b.cost<<std::endl;

    VertexTemp bb = pq.top();
    pq.pop();
    std::cout<<bb.from<<" "<<bb.to<<" "<<bb.cost<<std::endl;
    
    
    
	std::cout << "Hello, World!\n";
	timerrecord.stop_timer();

	return 0;
}
