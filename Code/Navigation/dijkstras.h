//
//  dijkstras.h
//  Navigation
//
//  Created by Anders Launer Bæk on 31/10/14.
//  Copyright (c) 2014 Anders Launer Bæk. All rights reserved.
//

#ifndef __Navigation__dijkstras__
#define __Navigation__dijkstras__

#include <stdio.h>
#include <string>
#include "Graph.h"
#include <fstream>
#include "Vertex.h"
/*struct Com {
    bool operator()(const std::pair<Vertex*, int> &a ,const std::pair<Vertex*, int> &b ) const {
        return b.second < a.second;
    }
};*/

class dijkstras{
    typedef std::priority_queue<std::pair<Vertex*, int>, std::vector<std::pair<Vertex*, int> >, Comp> diQueue;
public:
    dijkstras(std::string, Graph&);
    void getDist();
    diQueue dijkstrasQueue;
    
    
private:
    int distSum;
    
    
    
};
#endif /* defined(__Navigation__dijkstras__) */


