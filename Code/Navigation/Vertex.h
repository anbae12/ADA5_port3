#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <queue>

#ifndef VERTEX_H_
#define VERTEX_H_

//Inherents from priority_queue and adds get_container which returns the underlying container
template <class Container>
class Adapter : public Container {
public:
    typedef typename Container::container_type container_type;
    container_type &get_container() { return this->c; }
};

class Vertex;

//Comp used to compare values in prority_queue
struct Comp {
	bool operator()(const std::pair<Vertex*, int> &a ,const std::pair<Vertex*, int> &b ) const {
		return b.second < a.second;
	}
};

class Vertex {
    typedef std::priority_queue<std::pair<Vertex*, int>, std::vector<std::pair<Vertex*, int> >, Comp> C;
    typedef Adapter<C> Container;
public:
	Vertex(std::string value);
	std::string element;
    Container edge;
    bool known;
    int dist;
    Vertex* from;
};

#endif /* VERTEX_H_ */