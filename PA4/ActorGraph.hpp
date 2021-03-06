/*
 * ActorGraph.hpp
 * Author: Adrian Guthals
 * Date: 2/24/2015
 *
 * This file is meant to exist as a container for starter code that you can use to read the input file format
 * defined in movie_casts.tsv. Feel free to modify any/all aspects as you wish.
 */

#ifndef ACTORGRAPH_HPP
#define ACTORGRAPH_HPP

#include <iostream>
#include <unordered_map>
#include <string>

//#include "ActorNode.hpp"
//#include "MovieEdge.hpp"
#include "GraphNode.hpp"

// Maybe include some data structures here

using namespace std;


class ActorGraph {
public:
  // Maybe add class data structure(s) here

  ActorGraph(void);

  ~ActorGraph();

  // Maybe add some more methods here
  void build(string &ActorName, string &MovieName, int year);
  
  /** You can modify this method definition as you wish
   *
   * Load the graph from a tab-delimited file of actor->movie relationships.
   *
   * in_filename - input filename
   * use_weighted_edges - if true, compute edge weights as 1 + (2015 - movie_year), otherwise all edge weights will be 1
   *
   * return true if file was loaded sucessfully, false otherwise
   */
  bool loadFromFile(const char* in_filename, bool use_weighted_edges);

  void search(ofstream& out, string &actor1, string &actor2);
  
private:
  unordered_map<string, GraphNode*>* actors;
  unordered_map<string, GraphNode*>* movies;
};


#endif // ACTORGRAPH_HPP