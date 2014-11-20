/*
 * Matcher.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: exchizz
 */

#include "Matcher.h"

int Matcher::nLogn(int sum, std::vector<int> list){
	int hits = 0;
	sort(list.begin(), list.end());

	for(unsigned int i = 0; i < list.size(); ++i){
		int find_value = sum - list[i];

		if(std::binary_search(list.begin(), list.end(),find_value)){
			return 1;
		}
	}
	return 0;
}

int Matcher::nSquare(int sum, std::vector<int> &list){
	for (unsigned int i=0; i<list.size(); i++) {
		for (unsigned int j=0; j<list.size(); j++) {
			if (list[i]+list[j]==sum) {
				return 1;
			}
		}
	}
	return 0;
}

