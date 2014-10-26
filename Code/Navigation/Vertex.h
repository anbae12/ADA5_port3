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


#ifndef VERTEX_H_
#define VERTEX_H_

class Vertex {
	typedef std::vector<std::pair <Vertex*, int> > Edge;
public:
	Vertex(std::string value);
	std::string element;
	Edge edge;
};

#endif /* VERTEX_H_ */
