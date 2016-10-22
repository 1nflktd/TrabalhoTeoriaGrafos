#include "Graph.hpp"

Graph::Graph(int _vertices) : valued(false), directed(false), vertices(0)
{
	this->initialize(_vertices);
}

void Graph::initialize(int _vertices)
{
	this->vertices = _vertices;
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