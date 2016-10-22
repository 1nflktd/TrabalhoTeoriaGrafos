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
	void initialize(int _vertices, int _valued, int _directed);
	void addEdge(int vertex, int adjacentVertex, int weight);
	inline bool getValued() { return this->valued; }
	inline int getVertices() { return this->vertices; }
};

#endif