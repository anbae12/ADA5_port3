//
//  dijkstras.cpp
//  Navigation
//
//  Created by Anders Launer Baek on 31/10/14.
//  Copyright (c) 2014 Anders Launer Baek. All rights reserved.
//

#include "dijkstras.h"
void dijkstras::printPath(std::string to){
    while (!townNames.empty()) {
        std::cout <<townNames.front()<<" -> ";
        townNames.pop_front();
    }
    std::cout <<to<<std::endl;
}

int dijkstras::path(Vertex* from, Vertex* arrival, Graph &graph){
    if (arrival->element == from->element) {
        return arrival->dist;
    }
    townNames.push_front(arrival->from->element);
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
    path(graph.vertices[depTown], graph.vertices[arTown],graph);
    timerrecord.stop_timer();
    
    std::cout <<"---------------------"<<std::endl;
    std::cout <<"Departure: "<<depTown<<std::endl;
    std::cout <<"Arrival:   "<<to<<std::endl;
    std::cout <<"Shifts:    "<<townNames.size()-1<<": ";
    printPath(arTown);
    std::cout <<"Ticket:    "<< graph.vertices[arTown]->dist <<",- DKK"<<std::endl;
    std::cout <<"Duration:  "<< timerrecord.timetime <<" [ms]"<<std::endl;
    std::cout <<"---------------------"<<std::endl;
    
    std::ofstream myfile;
    myfile.open ("/Users/anderslaunerbaek/Documents/example.dot");
    //myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
}