/*
 * Vertex.h
 *
 *  Created on: Oct 24, 2014
 *      Author: exchizz
 */

#ifndef VERTEX_H_
#define VERTEX_H_
#include <string>

class Vertex {
public:
	std::string from;
	int cost;
	std::string city;
	Vertex(std::string mFrom, std::string mCity, int mCost);
	Vertex();
};

#endif /* VERTEX_H_ */
