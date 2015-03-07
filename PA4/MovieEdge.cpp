#include "MovieEdge.hpp"

#include <unordered_map>
#include <string>

using namespace std;

	void MovieEdge::add(GraphNode& actor){
		actorList.insert(make_pair(actor.name, actor));
	}
/*
	ActorNode* MoviEdge::getNext(){
		bool flag = true;
		if(flag){
			list<ActorNode*> temp (actorList);
			flag = false;
			return temp.pop_back();
		}
		else if(temp.size() == 0)
			return 0;
		else 
			return temp.pop_back();
	}
*/