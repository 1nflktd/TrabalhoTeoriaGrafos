#include <iostream>
#include "../../src/algorithms/BiconnectedComponents.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::BiconnectedComponents biconnectedComponents{g1.getGraph()};

	biconnectedComponents.run();
	biconnectedComponents.showResults();

	return 0;
}