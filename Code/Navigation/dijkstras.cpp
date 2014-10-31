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
    
    
    
    
    
    
    
    
    
   /* //////not working properly//////
    while (!graph.vertices[from]->edge.empty()) {
        dijkstrasQueue_1.push(graph.vertices[from]->edge.top());
        graph.vertices[from]->edge.pop();
    }
    //////////////////////////// 
    
    */
    
    
    /*
    while (!dijkstrasQueue_1.empty()) {
        from = dijkstrasQueue_1.top().first->element;
        
        std::cout<<"#1: "<<from<<std::endl;
        //graph.vertices[fromWhile]->from=fromWhile;
        lateXGenerator.AddVertex(from);
        
        
        while (!graph.vertices[from]->edge.empty()) {
            
            if (!graph.vertices[from]->edge.top().first->known) {
                std::string To = graph.vertices[from]->edge.top().first->element;
                std::cout<<"#2: "<<To<<std::endl;
                
                if (graph.vertices[To]->known == false) {
                    dijkstrasQueue_2.push(graph.vertices[To]->edge.top());
                }
                
                int distTo = graph.vertices[from]->edge.top().second;
                int distFrom= graph.vertices[from]->dist;
                int distSum = distTo+distFrom;
                distTo = distSum;
                
                if (distTo < graph.vertices[To]->edge.top().second) {
                    graph.vertices[To]->dist = distTo;
                    graph.vertices[To]->from=from; // used for setting depature town.
                    graph.vertices[To]->known=true;
                }
                
                
                lateXGenerator.AddEdge(from, To, distSum);
                graph.vertices[from]->edge.pop();
            
            
            } else
                break;
        }

        dijkstrasQueue_1.pop();
    }
    
    */
    
    
    
    
    
    std::ofstream myfile;
    myfile.open ("/Users/anderslaunerbaek/Documents/example.txt");
    //myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
}

