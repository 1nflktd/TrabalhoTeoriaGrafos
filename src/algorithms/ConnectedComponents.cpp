#include <sstream>
#include <iostream>

#include "DFS.hpp"
#include "ConnectedComponents.hpp"

void algorithms::ConnectedComponents::run()
{
	DFS dfs(this->graph, 0);
	dfs.run();	
	this->setGraph(dfs.getGraph());
	int nConnectedComponents = this->graph.getNConnectedComponents();
	std::stringstream stream;
	stream << "Numero de componentes conexos: " << nConnectedComponents << "\n";
	for (int i = 0; i < nConnectedComponents; ++i)
	{
		stream << "Componente: " << (i + 1) << "\n";
		stream << "Vertices: " << "\n";
		for (const auto & v : this->graph.getConnectedComponents(i))
		{
			stream << (v + 1) << " ";
		}
		stream << "\n";			
	}
	this->result += stream.str();
}

void algorithms::ConnectedComponents::showResults()
{
	std::cout << this->result;
}
