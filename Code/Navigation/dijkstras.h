#ifndef __Navigation__dijkstras__
#define __Navigation__dijkstras__

#include <stdio.h>
#include <string>
#include "Graph.h"
#include <fstream>
#include "Vertex.h"
#include "clock_timer.h"

struct Comp1 {
    bool operator()(const Vertex* a ,const Vertex* b ) const {
        return b->dist < a->dist;
    }
};

class dijkstras{
    typedef std::priority_queue<Vertex*, std::vector<Vertex* >, Comp1> diQueue;

public:
    dijkstras(std::string, std::string, Graph&);
    void getDist();
    int path(Vertex*, Vertex*, Graph&);
    diQueue dijkstrasQueue;
};
#endif /* defined(__Navigation__dijkstras__) */


