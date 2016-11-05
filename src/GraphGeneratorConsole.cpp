#include <iostream>

#include "GraphGeneratorConsole.hpp"

void GraphGeneratorConsole::read()
{
	char valued;
	int vertices;
	std::cin >> valued >> vertices;
	
	if (valued != 'V' && valued != 'N')
	{
		return; // throw error
	}

	this->graph.initialize(vertices, valued == 'V', true);

	for (int vertex = 0; vertex < vertices; ++vertex)
	{
		int n_adjacentVertices;
		std::cin >> n_adjacentVertices;

		for(int i = 0; i < n_adjacentVertices; ++i)
		{
			int adjacentVertice, weight = 1;
			std::cin >> adjacentVertice;

			if (this->graph.getValued()) 
				std::cin >> weight;

			this->graph.addEdge(vertex, --adjacentVertice, weight);
		}
	}	
}