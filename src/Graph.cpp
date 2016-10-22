#include "Graph.hpp"

void Graph::initialize(int _vertices, int _valued, int _directed)
{
	this->vertices = _vertices;
	this->valued = _valued;
	this->directed = _directed;
	this->matrix = Matrix(_vertices + 1, std::vector<int>(-1, _vertices + 1)); // initial vertex is 1, not 0...
	this->adjacencyList = AdjacencyList(_vertices + 1);
}

void Graph::addEdge(int vertex, int adjacentVertex, int weight)
{
	if (vertex <= 0 || vertex > this->vertices) 
	{
		return; // throw error
	}
	if (adjacentVertex <= 0 || adjacentVertex > this->vertices) 
	{
		return; // throw error
	}
	this->matrix[vertex][adjacentVertex] = weight;
	this->matrix[vertex].push_back(adjacentVertex);
	if (!this->directed)
	{
		this->matrix[adjacentVertex][vertex] = weight;
		this->matrix[adjacentVertex].push_back(vertex);
	}

}