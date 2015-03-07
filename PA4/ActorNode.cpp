#include "ActorNode.hpp"

#include <unordered_map>
#include <string>

using namespace std;
	
	void ActorNode::add(GraphNode& movie){
		movieList.insert(make_pair(movie.name, movie));
	}

/*	MovieEdge* ActorNode::getNext(){
		bool flag = true;
		if(flag){
			list<MovieEdge*> temp (adjList);
			flag = false;
			return temp.pop_back();
		}
		else if(temp.size() == 0)
			return 0;
		else 
			return temp.pop_back();
	}
	*/