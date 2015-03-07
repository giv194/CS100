#include "ActorGraph.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <set>

int main(int argc, char* argv[])
{
	if(argc < 5) {
        std::cerr << "run: test_in u test_search out" << std::endl;
		return 1;
    }
	ActorGraph* graph = new ActorGraph();
	graph->loadFromFile(argv[1], false);
	
	ifstream infile(argv[3]);
	ofstream writeout(argv[4]);
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
	if (record.size() != 2)
	{
	  // we should have exactly 2 columns
	  continue;
	}
	string first_actor(record[0]);
	string second_actor(record[1]);
	// we have an actor/movie relationship, now what?

	graph->search(writeout, first_actor, second_actor);
	
	}
	if (!infile.eof())
	{
		cerr << "Failed to read " << argv[3] << "!\n";
		return false;
	}
	infile.close();
	writeout.close();
}
