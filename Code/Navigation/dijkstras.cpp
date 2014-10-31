//
//  dijkstras.cpp
//  Navigation
//
//  Created by Anders Launer Bæk on 31/10/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

#include "dijkstras.h"


int dijkstras::path(Vertex* from, Vertex* arrival){
    if (arrival->element == from->element) {
        std::cout<<"YESS MAN: "<<"missing pris..." <<std::endl;
        return arrival->dist;
    }
    
    return path(from, arrival->from);
}

dijkstras::dijkstras(std::string from, Graph &graph){
    LateXGenerator lateXGenerator;
    if (graph.vertices.find(from) == graph.vertices.end()) {
        std::cout<<"Not found: "<<from<<std::endl;
        exit(0);
    }
    
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
    
    std::ofstream myfile;
    myfile.open ("/Users/anderslaunerbaek/Documents/example.dot");
    //myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
}

