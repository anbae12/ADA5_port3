/*
 * Vertex.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: exchizz
 */

#include "Vertex.h"

Vertex::Vertex(std::string value) {
	// TODO Auto-generated constructor stub
	element = value;
    known = false;
    dist = NULL;
    from="Unknown";  // Used in dijkstras
    
}


