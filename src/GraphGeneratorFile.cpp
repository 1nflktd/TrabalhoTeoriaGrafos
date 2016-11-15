#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

#include "GraphGeneratorFile.hpp"

void GraphGeneratorFile::read()
{
	std::ifstream infile{this->file, std::ios::binary};

	if (!infile)
	{
		throw std::runtime_error("Nao foi possível abrir o arquivo\n");
	}

	char valued;
	int vertices;
	infile >> valued >> vertices;
	
	this->graph.initialize(vertices, valued == 'V', true);

	int vertex = 0;
	std::string line;
	while (std::getline(infile, line))
	{
		if (std::all_of(line.begin(), line.end(), [](char c) {
				return std::isspace(static_cast<unsigned char>(c));
			})
		) continue;

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
