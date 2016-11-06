#include <iostream>
#include <limits>

#include "GraphGeneratorConsole.hpp"

void readInputClear()
{
	std::cin.clear(); //clear bad input flag
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	std::cout << "Input inválido. Escreva novamente.\n";
}

void GraphGeneratorConsole::read()
{
	char valued;
	int vertices;
		
	//executes loop if the input fails (e.g., no characters were read)
	while (((std::cout << "V para valorado e N para nao valorado: ") && !(std::cin >> valued)) || (valued != 'V' && valued != 'N'))
		readInputClear();

	while (((std::cout << "Numero de vertices: ") && !(std::cin >> vertices)) || (vertices <= 0))
		readInputClear();

	this->graph.initialize(vertices, valued == 'V', true);

	std::cout << "Cada linha é um vértice, na ordem. Ex: linha 1, vértice 1, etc.\n";
	if (this->graph.getValued())
		std::cout << "Digite o número de vértices adjacentes junto com cada vértice e o peso da aresta.\nEx: 2 1 2 2 3, dois vértices, vértice 1, aresta peso 2, e vértice 2, aresta peso 3.\n";
	else
		std::cout << "Digite o número de vértices adjacentes junto com cada vértice.\nEx: 2 1 2, dois vértices, 1 e 2.\n";

	for (int vertex = 0; vertex < vertices; ++vertex)
	{
		std::cout << "Vértice: " << (vertex+1) << "\n";
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