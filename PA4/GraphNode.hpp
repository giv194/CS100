#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP


#include <string>
#include <unordered_map>

using namespace std;

class GraphNode{
public:
	
	GraphNode(string& s, int i);

	string name;
	int weight;
	int dist;
	GraphNode* prev;

	unordered_map<string, GraphNode> adj;

	void add(GraphNode& node);
};
#endif//GRAPHNODE_HPP