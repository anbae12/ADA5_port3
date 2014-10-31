/*
 * Vertex.h
 *
 *  Created on: Oct 26, 2014
 *      Author: exchizz
 */
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <queue>


#ifndef VERTEX_H_
#define VERTEX_H_

template <class Container>
class Adapter : public Container {
public:
    typedef typename Container::container_type container_type;
    container_type &get_container() { return this->c; }
};

class Vertex;
struct Comp {
	bool operator()(const std::pair<Vertex*, int> &a ,const std::pair<Vertex*, int> &b ) const {
		return b.second < a.second;
	}
};

//typedef std::priority_queue<std::pair<Vertex*, int>, std::vector<std::pair<Vertex*, int> >, Comp> Edge;
class Vertex {

	//typedef std::vector<std::pair <Vertex*, int> > Edge;

public:
	Vertex(std::string value);
	std::string element;
	//Edge edge;

    typedef std::priority_queue<std::pair<Vertex*, int>, std::vector<std::pair<Vertex*, int> >, Comp> C;
    typedef Adapter<C> Container;

    Container edge;
    bool known;
    int dist;
    std::string from;
};

#endif /* VERTEX_H_ */
