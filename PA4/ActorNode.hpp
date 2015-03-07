#ifndef ACTORNODE_HPP
#define ACTORNODE_HPP

#include "GraphNode.hpp"
#include <string>
#include <unordered_map>

using namespace std;

class ActorNode{
public:
	string name;
	unordered_map<string, GraphNode> movieList;

	ActorNode(string actor) : movieList(0) {
		GraphNode(actor, -1);
	};

	void add(GraphNode& movie);
/*	MovieEdge* getNext();*/

};
#endif //ACTORNODE_HPP