#include <iostream>
#include "../../src/algorithms/ConnectedComponents.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::ConnectedComponents connectedComponents{g1.getGraph()};

	connectedComponents.run();
	connectedComponents.showResults();

	return 0;
}