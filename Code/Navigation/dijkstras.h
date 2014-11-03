#ifndef __Navigation__dijkstras__
#define __Navigation__dijkstras__

#include <stdio.h>
#include <string>
#include <fstream>
#include <deque>
#include "Graph.h"
#include "Vertex.h"
#include "clock_timer.h"
#include <ctime>

struct Comp1 {
    bool operator()(const Vertex* a ,const Vertex* b ) const {
        return b->dist < a->dist;
    }
};

class dijkstras{
    typedef std::priority_queue<Vertex*, std::vector<Vertex* >, Comp1> diQueue;
public:
    dijkstras(std::string, std::string, Graph&);
    std::pair<std::string, int> path(Vertex*, Vertex*);
    diQueue dijkstrasQueue;
};

#endif /* defined(__Navigation__dijkstras__) */
