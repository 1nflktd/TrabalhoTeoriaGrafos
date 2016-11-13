#include <iostream>

#include "GraphGeneratorConsole.hpp"
#include "Functions.hpp"

void GraphGeneratorConsole::read()
{
	char valued;
	int vertices;
		
	//executes loop if the input fails (e.g., no characters were read)
	while (((std::cout << "V para valorado e N para nao valorado: ") && !(std::cin >> valued)) || (valued != 'V' && valued != 'N'))
		functions::readInputClear();

	while (((std::cout << "Numero de vertices: ") && !(std::cin >> vertices)) || (vertices <= 0))
		functions::readInputClear();

	this->graph.initialize(vertices, valued == 'V', true);

	std::cout << "Cada linha e um vertice, na ordem. Ex: linha 1, vertice 1, etc.\n";
	if (this->graph.getValued())
		std::cout << "Digite o número de vertices adjacentes junto com cada vertice e o peso da aresta.\nEx: 2 1 2 2 3, dois vertices, vertice 1, aresta peso 2, e vertice 2, aresta peso 3.\n";
	else
		std::cout << "Digite o número de vertices adjacentes junto com cada vertice.\nEx: 2 1 2, dois vertices, 1 e 2.\n";

	for (int vertex = 0; vertex < vertices; ++vertex)
	{
		std::cout << "Vertice: " << (vertex+1) << "\n";
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