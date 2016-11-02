#include <fstream>
#include <sstream>
#include <iostream>

#include "GraphGeneratorFile.hpp"

void GraphGeneratorFile::read()
{
	std::ifstream infile{this->file};
	char valued;
	int vertices;
	infile >> valued >> vertices;
	
	this->graph.initialize(vertices, valued == 'V', false);

	int vertex = 0;
	std::string line;
	while(std::getline(infile, line))
	{
		if (line.empty()) continue;
		std::istringstream iss(line);
		int n_adjacentVertices;
		iss >> n_adjacentVertices;

		for(int i = 0; i < n_adjacentVertices; ++i)
		{
			int adjacentVertice, weight = 1;
			iss >> adjacentVertice;

			if (this->graph.getValued()) 
				iss >> weight;

			this->graph.addEdge(vertex, --adjacentVertice, weight);
		}
		++vertex;
	}
}
