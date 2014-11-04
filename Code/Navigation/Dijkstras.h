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
#include <memory>
#include <limits>
struct Comp1 {
    bool operator()(const Vertex* a ,const Vertex* b ) const {
        return b->dist < a->dist;
    }
};

class DijkResult{
public:
	int Shifts;
	int Ticket;
	float Duration;
	std::string Path;

	DijkResult(int shifts, int ticket, float duration, std::string path){
		this->Shifts = shifts;
		this->Ticket = ticket;
		this->Duration = duration;
		this->Path = path;
	}
};
class Dijkstras{
    typedef std::priority_queue<Vertex*, std::vector<Vertex* >, Comp1> diQueue;
public:
    Dijkstras(std::shared_ptr<Graph> graph);
    DijkResult Run(std::string from, std::string to);
    std::pair<std::string, int> path(Vertex*, Vertex*);
    diQueue dijkstrasQueue;
private:
    std::shared_ptr<Graph> mGraph;
};

#endif
