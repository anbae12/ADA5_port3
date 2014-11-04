#include "Dijkstras.h"

std::pair<std::string, int> Dijkstras::path(Vertex* from, Vertex* arrival){
	if (arrival->element == from->element) {
		return std::make_pair(arrival->element, 0);
	}
	auto val = path(from, arrival->from);
	return std::make_pair(val.first + " -> " + arrival->element, val.second+1 );
}
DijkResult Dijkstras::Run(std::string from, std::string to){
	LateXGenerator lateXGenerator;
	clock_timer timerrecord;

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

	lateXGenerator.AddVertex(from);

	dijkstrasQueue.push(mGraph->vertices[from]);

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
			lateXGenerator.AddEdge(from, to, cost);
		}
		//mGraph->vertices[from]->known=true; <- unsued ?
	}

	timerrecord.start_timer();
	auto route = path(mGraph->vertices[depTown], mGraph->vertices[arTown]);
	timerrecord.stop_timer();

	std::ofstream myfile;
	myfile.open ("/Users/anderslaunerbaek/Documents/example.dot");
	//myfile.open ("example.txt");
	myfile << lateXGenerator.getOutput();
	myfile.close();
	return DijkResult(route.second,mGraph->vertices[arTown]->dist,timerrecord.duration, route.first);
}

Dijkstras::Dijkstras(std::shared_ptr<Graph> graph){
	this->mGraph = graph;

	for(auto it = mGraph->vertices.begin(); it != mGraph->vertices.end(); ++it){
		for(auto itwo = it->second->edge.get_container().begin(); itwo != it->second->edge.get_container().end(); ++itwo){
			it->second->dist = std::numeric_limits<int>::max();
			//it->second->known = false;
			it->second->from = NULL;
		}
	}
}; 
