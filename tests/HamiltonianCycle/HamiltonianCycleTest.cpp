#include <iostream>
#include "../../src/algorithms/HamiltonianCycle.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "parametros invalidos. segundo parametro nome do arquivo.\n";
		return 0;
	}

	GraphGeneratorFile g1{argv[1]};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::HamiltonianCycle hamCycle{g1.getGraph()};

	hamCycle.run();
	hamCycle.showResults();

	return 0;
}
