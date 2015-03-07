#ifndef MOVIEEDGE_HPP
#define MOVIEEDGE_HPP

#include "ActorNode.hpp"
#include <string>
#include <unordered_map>

using namespace std;

class MovieEdge{
public:
	
	unordered_map<string, GraphNode> actorList;
	int weight;
	string name;

	MovieEdge(string name, int year) : name(name), actorList(0) {
		weight = (1 + (2015 - year));
		GraphNode(name, weight);		
	};

	void add(GraphNode& actor);

//	ActorNode* getNext();

};
#endif //MOVIEEDGE_HPP