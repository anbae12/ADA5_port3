#include "Dijkstras.h"

std::pair<std::string, int> Dijkstras::path(Vertex* from, Vertex* arrival){
	if (arrival->element == from->element) {
		return std::make_pair(arrival->element, 0);
	}
	auto val = path(from, arrival->from);
	return std::make_pair(val.first + " -> " + arrival->element, val.second+1 );
}
DijkResult Dijkstras::Run(std::string from, std::string to){
	if (mGraph->vertices.find(from) == mGraph->vertices.end()) {
		std::cout<<"Not found: "<<from<<std::endl;
		exit(0);
	}
	if (mGraph->vertices.find(to) == mGraph->vertices.end()) {
		std::cout<<"Not found: "<<to<<std::endl;
		exit(0);
	}
	std::string depTown = from;
	std::string arTown = to;

	mGraph->vertices[from]->dist=0;
	std::cout << "ch4 \n";
	dijkstrasQueue.push(mGraph->vertices[from]);
	std::cout << "ch5 \n";
	while (!dijkstrasQueue.empty()) {
		from = dijkstrasQueue.top()->element;
		dijkstrasQueue.pop();
		while (!mGraph->vertices[from]->edge.empty()) {
			std::string to = mGraph->vertices[from]->edge.top().first->element;
			int cost  = mGraph->vertices[from]->edge.top().second;

			int edgeplusnode = cost + mGraph->vertices[from]->dist;

			if ( edgeplusnode <  mGraph->vertices[to]->dist) {
				mGraph->vertices[to]->dist=edgeplusnode;
				mGraph->vertices[to]->from=mGraph->vertices[from];
			}
			dijkstrasQueue.push(mGraph->vertices[from]->edge.top().first );
			mGraph->vertices[from]->edge.pop();
		}
	}
	std::cout << "ch6 \n";
	auto route = path(mGraph->vertices[depTown], mGraph->vertices[arTown]);
	std::cout << "ch7 \n";
	return DijkResult(route.second,mGraph->vertices[arTown]->dist,0, route.first);
}

Dijkstras::Dijkstras(std::shared_ptr<Graph> graph){

	this->mGraph = graph;

	for(auto it = mGraph->vertices.begin(); it != mGraph->vertices.end(); ++it){
		it->second->dist = std::numeric_limits<int>::max();
		it->second->from = NULL;
		for(auto itwo = it->second->edge.get_container().begin(); itwo != it->second->edge.get_container().end(); ++itwo){
			itwo->first->dist = std::numeric_limits<int>::max();
			itwo->first->from = NULL;
		}
	}
}; 
