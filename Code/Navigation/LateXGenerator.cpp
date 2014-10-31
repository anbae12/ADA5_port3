/*
 * LateXGenerator.cpp
 *
 *  Created on: Oct 26, 2014
 *      Author: exchizz
 */

#include "LateXGenerator.h"
#include<sstream>

LateXGenerator::LateXGenerator() {
	output = "	digraph G{";
}


void LateXGenerator::AddVertex(std::string name){
	/*
	digraph G{
	a [label="Node A"];
	b [label="Node B"];
	a->b[label=" An edge"];
	}
	*/
	output += name + " [label=\"" + name + "\"];";
}

void LateXGenerator::AddEdge(std::string From, int fromPrice, std::string To, int Cost){
	std::ostringstream os;
	os << Cost;

	std::ostringstream os1;
	os1 << fromPrice;
	output += From + "->" + To + "[label=\"" + os.str() + "(" + os1.str() +  ")\"];";
}

std::string LateXGenerator::getOutput(){
	return output + "}";
}
