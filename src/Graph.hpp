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
	int vertices;
	Matrix matrix;
	AdjacencyList adjacencyList;
public:
	Graph() : valued(false), directed(false), vertices(0) {}
	Graph(int _vertices);
	void initialize(int _vertices);
	inline void setValued(int _valued) { this->valued = _valued; }
	inline void setDirected(int _directed) { this->directed = _directed; }
	void addEdge(int vertex, int adjacentVertex, int weight);
};

#endif