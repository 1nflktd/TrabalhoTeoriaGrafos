#include <iostream>
#include "../../src/algorithms/BiconnectedComponents.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "insira o nome do grafo\n";
		return 0;
	}

	try
	{
		GraphGeneratorFile g1{argv[1]};

		std::cout << "graph1\n";
		g1.getGraph().printGraphMatrix();

		algorithms::BiconnectedComponents biconnectedComponents{g1.getGraph()};

		biconnectedComponents.run();
		biconnectedComponents.showResults();
	}
	catch (const std::runtime_error & e)
	{
		std::cout << e.what() << "\n";		
	}
	
	return 0;
}