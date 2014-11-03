#include "dijkstras.h"

std::pair<std::string, int> dijkstras::path(Vertex* from, Vertex* arrival){
   if (arrival->element == from->element) {
	   return std::make_pair(arrival->element, 0);
    }
   auto val = path(from, arrival->from);
   return std::make_pair(val.first + " -> " + arrival->element, val.second+1 );
}

dijkstras::dijkstras(std::string from,std::string to, Graph &graph){
    LateXGenerator lateXGenerator;
    clock_timer timerrecord;
    
    if (graph.vertices.find(from) == graph.vertices.end()) {
        std::cout<<"Not found: "<<from<<std::endl;
        exit(0);
    }
    std::string depTown = from;
    std::string arTown = to;
    
    graph.vertices[from]->dist=0;
    
    lateXGenerator.AddVertex(from);
    
    dijkstrasQueue.push(graph.vertices[from]);
    
    while (!dijkstrasQueue.empty()) {
        from = dijkstrasQueue.top()->element;
        dijkstrasQueue.pop();
        while (!graph.vertices[from]->edge.empty()) {
            std::string to = graph.vertices[from]->edge.top().first->element;
            int cost  = graph.vertices[from]->edge.top().second;
            
            int edgeplusnode = cost + graph.vertices[from]->dist;
            
            if ( edgeplusnode <  graph.vertices[to]->dist) {
                graph.vertices[to]->dist=edgeplusnode;
                graph.vertices[to]->from=graph.vertices[from];
            }
            dijkstrasQueue.push(graph.vertices[from]->edge.top().first );
            graph.vertices[from]->edge.pop();
            lateXGenerator.AddEdge(from, to, cost);
        }
        graph.vertices[from]->known=true;
    }
    
    timerrecord.start_timer();
    auto route = path(graph.vertices[depTown], graph.vertices[arTown]);
    timerrecord.stop_timer();
    
    std::cout <<"---------------------"<<std::endl;
    std::cout <<"Departure: "<<depTown<<std::endl;
    std::cout <<"Arrival:   "<<to<<std::endl;
    std::cout <<"Shifts:    "<< route.second <<": " << route.first << std::endl;
    std::cout <<"Ticket:    "<< graph.vertices[arTown]->dist <<",- DKK"<<std::endl;
    std::cout <<"Duration:  "<< timerrecord.duration <<" [ms]"<<std::endl;
    std::cout <<"---------------------"<<std::endl;
    
    std::ofstream myfile;
    myfile.open ("/Users/anderslaunerbaek/Documents/example.dot");
    //myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
}; 
