#include <iostream>
#include "../../src/algorithms/HamiltonianCycle.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::HamiltonianCycle hamCycle{g1.getGraph()};

	hamCycle.run();
	hamCycle.showResults();

	return 0;
}
