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

void LateXGenerator::AddEdge(std::string From, std::string To, int Cost){
	std::ostringstream os;
	os << Cost;
	output += From + "->" + To + "[label=\"" + os.str() +  "\"];";
}

std::string LateXGenerator::getOutput(){
	return output + "}";
}