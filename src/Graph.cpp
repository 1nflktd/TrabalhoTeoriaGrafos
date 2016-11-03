#include <iostream>
#include <vector>

#include "Graph.hpp"

void Graph::initialize(int _vertices, int _valued, int _directed)
{
	this->vertices = _vertices;
	this->valued = _valued;
	this->directed = _directed;
	this->matrix = Matrix(_vertices, std::vector<int>(_vertices, -1)); // initial vertex is 1, not 0...
	this->adjacencyList = AdjacencyList(_vertices);
	this->connectedComponents = AdjacencyList(_vertices); // if every connected component is degree 1
	this->nConnectedComponents = _vertices;
	this->biconnectedComponents = Edges(_vertices); // if every connected component is degree 1
	this->nBiconnectedComponents = _vertices;
}

void Graph::addEdge(int vertex, int adjacentVertex, int weight)
{
	if (vertex < 0 || vertex >= this->vertices) 
	{
		return; // throw error
	}
	if (adjacentVertex < 0 || adjacentVertex >= this->vertices) 
	{
		return; // throw error
	}
	this->matrix[vertex][adjacentVertex] = weight;
	this->adjacencyList[vertex].push_back(adjacentVertex);
	if (!this->directed)
	{
		this->matrix[adjacentVertex][vertex] = weight;
		this->adjacencyList[adjacentVertex].push_back(vertex);
	}
}

void Graph::printGraphMatrix()
{
	for(const auto & m : this->matrix)
	{
		for (const auto & x : m)
		{
			std::cout << x << "\t";
		}
		std::cout << "\n";
	}
}

void Graph::addConnectedComponent(int connectedComponent, int vertex)
{
	if (connectedComponent < 0 || connectedComponent >= this->nConnectedComponents) 
	{
		return; // throw error
	}
	if (vertex < 0 || vertex >= this->vertices) 
	{
		return; // throw error
	}

	this->connectedComponents[connectedComponent].push_back(vertex);
}

void Graph::addBiconnectedComponent(int biconnectedComponent, const std::pair<int, int> & edge)
{
	if (biconnectedComponent < 0 || biconnectedComponent >= this->nBiconnectedComponents)
	{
		return; // throw error
	}

	this->biconnectedComponents[biconnectedComponent].push_back(edge);
}
