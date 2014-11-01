#ifndef __Navigation__dijkstras__
#define __Navigation__dijkstras__

#include <stdio.h>
#include <string>
#include <fstream>
#include <deque>
#include "Graph.h"
#include "Vertex.h"
#include "clock_timer.h"


struct Comp1 {
    bool operator()(const Vertex* a ,const Vertex* b ) const {
        return b->dist < a->dist;
    }
};

class dijkstras{
    typedef std::priority_queue<Vertex*, std::vector<Vertex* >, Comp1> diQueue;
    typedef std::deque<std::string> Names;

public:
    dijkstras(std::string, std::string, Graph&);
    void printPath(std::string);
    int path(Vertex*, Vertex*, Graph&);
    diQueue dijkstrasQueue;
    Names townNames;
};
#endif /* defined(__Navigation__dijkstras__) */
