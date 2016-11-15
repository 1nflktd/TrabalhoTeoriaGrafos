#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>

using VecInt = std::vector<int>;
using ListInt = std::list<int>;
using Matrix = std::vector<VecInt>;
using AdjacencyList = std::vector<ListInt>;
using Edges = std::vector<std::list<std::pair<int, int>>>;

class Graph
{
	bool valued;
	bool directed;
	int vertices; // total vertices
	int edges;	// total edges
	VecInt degree; // used for undirected graphs
	VecInt indegree; // used for directed graphs
	VecInt outdegree; // used for directed graphs
	Matrix matrix;
	AdjacencyList adjacencyList;

	int nConnectedComponents;
	AdjacencyList connectedComponents;
	
	int nBiconnectedComponents;
	Edges biconnectedComponents;
public:
	Graph() : valued(false), directed(false), vertices(0), edges(0), degree(), indegree(), outdegree() {}
	void initialize(int _vertices, int _valued, int _directed);
	void addEdge(int vertex, int adjacentVertex, int weight);
	inline bool getValued() const { return this->valued; }
	inline int getVertices() const { return this->vertices; }
	inline int getEdges() const { return this->edges; }
	inline int getDegree(int v) const { return this->degree[v]; }
	inline int getIndegree(int v) const { return this->indegree[v]; }
	inline int getOutdegree(int v) const { return this->outdegree[v]; }
	inline int operator()(int row, int colunm) const { return this->matrix[row][colunm]; }
	inline ListInt getAdjacencyList(int v) const { return this->adjacencyList[v]; }
	inline AdjacencyList getAdjacencyList() const { return this->adjacencyList; }

	// connected components
	inline void setNConnectedComponents(int _nConnectedComponents) { this->nConnectedComponents = _nConnectedComponents; }
	inline int getNConnectedComponents() const { return this->nConnectedComponents; }
	void addConnectedComponent(int connectedComponent, int vertex);
	inline AdjacencyList getConnectedComponents() const { return this->connectedComponents; }
	inline std::list<int> getConnectedComponents(int v) const { return this->connectedComponents[v]; }

	// biconnected components
	inline void setNBiconnectedComponents(int _nBiconnectedComponents) { this->nBiconnectedComponents = _nBiconnectedComponents; }
	inline int getNBiconnectedComponents() const { return this->nBiconnectedComponents; }
	void addBiconnectedComponent(int biconnectedComponent, const std::pair<int, int> & edge);
	inline Edges getBiconnectedComponents() const { return this->biconnectedComponents; }
	inline std::list<std::pair<int, int>> getBiconnectedComponents(int v) const { return this->biconnectedComponents[v]; }

	void printGraphMatrix();
	int getNonIsolatedVertex() const;
};

#endif