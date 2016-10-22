#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>

using Matrix = std::vector<std::vector<int>>;
using AdjacencyList = std::vector<std::list<int>>;

class Graph
{
	bool valued;
	bool directed;
	Matrix matrix;
	AdjacencyList adjacencyList;
public:
	Graph() {}
};

#endif