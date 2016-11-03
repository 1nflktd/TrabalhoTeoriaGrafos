#include <sstream>
#include <iostream>

#include "DFS.hpp"
#include "BiconnectedComponents.hpp"

void algorithms::BiconnectedComponents::run()
{
	DFS dfs(this->graph, 0);
	dfs.run();	
	this->setGraph(dfs.getGraph());
	int nBiconnectedComponents = this->graph.getNBiconnectedComponents();
	std::stringstream stream;
	stream << "Numero de componentes biconexos: " << nBiconnectedComponents << "\n";
	for (int i = 0; i < nBiconnectedComponents; ++i)
	{
		stream << "Componente: " << (i + 1) << "\n";
		stream << "Arestas: " << "\n";
		for (const auto & v : this->graph.getBiconnectedComponents(i))
		{
			stream << (v.first + 1) << " - " << (v.second + 1) << " ";
		}
		stream << "\n";			
	}
	this->result += stream.str();
}

void algorithms::BiconnectedComponents::showResults()
{
	std::cout << this->result;
}
