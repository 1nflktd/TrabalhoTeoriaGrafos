#include <iostream>
#include "../../src/algorithms/FordFulkerson.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	int source = 1, target = g1.getGraph().getVertices(); // read from console
	algorithms::FordFulkerson fordFulkerson{g1.getGraph(), --source, --target};

	fordFulkerson.run();
	fordFulkerson.showResults();

	return 0;
}
