#include "dijkstras.h"

int dijkstras::path(Vertex* from, Vertex* arrival, Graph &graph){
    if (arrival->element == from->element) {
        //std::cout<<"YESS MAN: "<<"missing pris..." <<std::endl;
        std::cout<<""<<std::endl;
        return arrival->dist;
    }
    std::cout<<" <- "<< arrival->from->element;
    return path(from, arrival->from, graph);
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
    //graph.vertices[from]->from = graph.vertices[from]; // used for setting depature town.
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
                //std::cout<<graph.vertices[from]->element<<std::endl;
            }
            dijkstrasQueue.push(graph.vertices[from]->edge.top().first );
            graph.vertices[from]->edge.pop();
            lateXGenerator.AddEdge(from, to, cost);
        }
        graph.vertices[from]->known=true;
    }
    
    
    timerrecord.start_timer();
    
    int price = graph.vertices[arTown]->dist;
    auto time = timerrecord.stop_timer();
    
    std::cout <<"---------------------"<<std::endl;
    std::cout <<"Departure: "<<depTown<<std::endl;
    std::cout <<"Arrival:   "<<to<<std::endl;
    std::cout <<"Ticket:    "<< price <<",- DKK"<<std::endl;
    std::cout <<"Duration:  "<< time <<" [ms]"<<std::endl;
    std::cout <<"---------------------"<<std::endl;
    
    path(graph.vertices[depTown], graph.vertices[arTown],graph);
    
    
    std::ofstream myfile;
    myfile.open ("/Users/anderslaunerbaek/Documents/example.dot");
    //myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
}
