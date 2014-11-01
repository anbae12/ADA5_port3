/*
 * Vertex.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: exchizz
 */

#include "Vertex.h"
#include <limits> 

Vertex::Vertex(std::string value) {
	// TODO Auto-generated constructor stub
	element = value;
    known = false;
    dist = std::numeric_limits<int>::max();
    from=NULL;  // Used in dijkstras
}