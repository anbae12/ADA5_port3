/*
 * LateXGenerator.h
 *
 *  Created on: Oct 26, 2014
 *      Author: exchizz
 */

#include <string>
#ifndef LATEXGENERATOR_H_
#define LATEXGENERATOR_H_

class LateXGenerator {
public:
	LateXGenerator();
	std::string output;
	void AddVertex(std::string name);
	void AddEdge(std::string, std::string, int);
	std::string getOutput();

};

#endif /* LATEXGENERATOR_H_ */
