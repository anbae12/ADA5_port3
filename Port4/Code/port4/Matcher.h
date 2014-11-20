/*
 * Matcher.h
 *
 *  Created on: Nov 19, 2014
 *      Author: exchizz
 */

#ifndef MATCHER_H_
#define MATCHER_H_
#include <vector>
#include <algorithm>
#include <iostream>

class Matcher {
public:
	Matcher();
	int nLogn(int sum, std::vector<int> list);
	int nSquare(int sum, std::vector<int> &list);
	int binarySearch(int key, std::vector<int> list, int lower);
	bool LookNFound(int sum, std::vector<int> list);
};

#endif /* MATCHER_H_ */