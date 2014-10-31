//
//  dijkstras.cpp
//  Navigation
//
//  Created by Anders Launer Bæk on 31/10/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

#include "dijkstras.h"

dijkstras::dijkstras(std::string from, Graph &graph){
    LateXGenerator lateXGenerator;
    if (graph.vertices.find(from) == graph.vertices.end()) {
        std::cout<<"Not found: "<<from<<std::endl;
        exit(0);
    }
    
    
    graph.vertices[from]->dist=0;
    graph.vertices[from]->from=from; // used for setting depature town.
    lateXGenerator.AddVertex(from);
    
    
    dijkstrasQueue.push(graph.vertices[from]->edge.top());
    while (!dijkstrasQueue.empty()) {
        from = dijkstrasQueue.top().first->element;
        dijkstrasQueue.pop();
        lateXGenerator.AddVertex(from);
        while (!graph.vertices[from]->edge.empty()) {
            std::string to = graph.vertices[from]->edge.top().first->element;
            int cost  = graph.vertices[from]->edge.top().second;
            
            graph.vertices[to]->from=from;
            
            
            int edgeplusnode = cost + graph.vertices[from]->dist;
            
            
            if ( edgeplusnode <  graph.vertices[to]->dist) {
                graph.vertices[to]->dist=cost;
            }
            dijkstrasQueue.push(graph.vertices[from]->edge.top());
            graph.vertices[from]->edge.pop();
            lateXGenerator.AddEdge(from+std::to_string(graph.vertices[from]->dist), to+std::to_string(graph.vertices[to]->dist=cost), cost);
        }
        graph.vertices[from]->known=true;
        
    }
    
    
    
    
    
    
    
    
    
 
    
    
    std::ofstream myfile;
    myfile.open ("/Users/anderslaunerbaek/Documents/example.dot");
    //myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
}

