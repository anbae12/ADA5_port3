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
    
    
    
    
    lateXGenerator.AddVertex(from);
    while (!graph.vertices[from]->edge.empty()) {
        
        std::string To = graph.vertices[from]->edge.top().first->element;
        
    
        dijkstrasQueue.push(graph.vertices[from]->edge.top());
        
        
        int distTo = graph.vertices[from]->edge.top().second;
        int distFrom= graph.vertices[from]->dist;
        int distSum = distTo+distFrom;
        distTo = distSum;
        
        if (distTo < graph.vertices[To]->edge.top().second) {
            graph.vertices[To]->dist = distTo;
        }
        
        

        lateXGenerator.AddEdge(from, To, distSum);
        
        graph.vertices[from]->edge.pop();
    }
    
    ///dijkstras(dijkstrasQueue.top().first->element, graph);
    
    
    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile << lateXGenerator.getOutput();
    myfile.close();
    
    
}

