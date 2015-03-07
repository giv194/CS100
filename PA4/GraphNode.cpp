#include "GraphNode.hpp"

#include <unordered_map>
#include <string>

using namespace std;

GraphNode::GraphNode(string& s, int i){
	name = s;
	weight = i;
	prev = 0;
}

void GraphNode::add(GraphNode* node){
	adj.insert(make_pair(node->name, node));
}