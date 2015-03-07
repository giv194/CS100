/*
 * ActorGraph.cpp
 * Author: Adrian Guthals
 * Date: 2/24/2015
 *
 * This file is meant to exist as a container for starter code that you can use to read the input file format
 * defined in movie_casts.tsv. Feel free to modify any/all aspects as you wish.
 */
#include "ActorGraph.hpp"
 
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void found(ofstream& out, GraphNode* end);

ActorGraph::ActorGraph(void) : actors(0), movies (0){
}

ActorGraph::~ActorGraph(){
/*  actors.erase(actors.begin(), actors.end());
  delete actors;
  movies.erase(movies.begin(), movies.end());
  delete movies;
*/
}


bool ActorGraph::loadFromFile(const char* in_filename, bool use_weighted_edges)
{
  //ActorGraph::actors;
  // Initialize the file stream
  ifstream infile(in_filename);
  bool have_header = false;
  
  // keep reading lines until the end of file is reached
  while (infile)
  {
    string s;
    
    // get the next line
    if (!getline( infile, s )) break;
    
    if (!have_header)
    {
      // skip the header
      have_header = true;
      continue;
    }

    istringstream ss( s );
    vector <string> record;

    while (ss)
    {
      string next;
      
      // get the next string before hitting a tab character and put it in 'next'
      if (!getline( ss, next, '\t' )) break;
      
      record.push_back( next );
    }
    
    if (record.size() != 3)
    {
      // we should have exactly 3 columns
      continue;
    }
    
    string actor_name(record[0]);
    string movie_title(record[1]);
    int movie_year = stoi(record[2]);
    
    build(actor_name, movie_title, movie_year);
    // we have an actor/movie relationship, now what?
  }
  
  if (!infile.eof())
  {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
  }
  infile.close();
  
  return true;
}

void ActorGraph::build(string &actorName, string &movieName, int year){
  //unordered_map<string, GraphNode*> actors;
  //unordered_map<string, GraphNode*> movies; 

  unordered_map<string, GraphNode*>::iterator it = actors->find(actorName);
  if(it == actors->end()){
    GraphNode* a = new GraphNode(actorName, 0);
    actors->insert(make_pair(actorName, a));
  }
  unordered_map<string, GraphNode*>::iterator mit = movies->find(movieName);
  if(mit == movies->end()){
    GraphNode* m = new GraphNode(movieName, 1 + (2015 - year));
    movies->insert(make_pair(movieName, m));
  }
  it = actors->find(actorName);
  mit = movies->find(movieName);
  it->second->add((mit->second));
  mit->second->add((it->second));

/*
  if(actors[ActorName] == 0)
    actors[ActorName] = new GraphNode(ActorName, -1);

  if(movies[MovieName + to_string(year)] == 0)
    movies[MovieName + to_string(year)] = new GraphNode(MovieName, 1 + (2015 - year));

  movies[MovieName + to_string(year)]->add(actors[ActorName]);
  actors[ActorName]->add(movies[MovieName + to_string(year)]);
  */
}

void ActorGraph::search(ofstream& out, string& actor1, string& actor2){
  unordered_map<string, GraphNode*>::iterator iit = actors->begin();
  for(;iit != actors->end(); iit++){
    iit->second->dist = numeric_limits<int>::max();
  }
  unordered_map<string, GraphNode*>::iterator sit = actors->find(actor1);
  sit->second->dist = 0;
  queue<GraphNode*> bfs;
  int dist = 0;
  bfs.push(sit->second);
  while(!bfs.empty()){
    dist++;
    GraphNode* current = bfs.front();
    bfs.pop();
    if(current->dist != numeric_limits<int>::max()){
      if(!current->name.compare(actor2)){
        found(out, current);
        return;
      }
      iit = current->adj.begin();
      for(; iit != current->adj.end(); iit++){
        bfs.push(iit->second);
      }
    }
  }
}

void found(ofstream& out, GraphNode* end){
  if(end->prev == 0) {
    out << "(" << end->name << ")";
    return;
  }
  found(out, end->prev);
  if(end->weight == -1) {
    out << "(" << end->name << ")";
  }
  else
    out << "--[" << end->name << "#@" << 1 + 2015 - (end->weight) << "]-->";
  return;
}






