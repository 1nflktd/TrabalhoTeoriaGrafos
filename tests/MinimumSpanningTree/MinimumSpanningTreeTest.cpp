#include <iostream>
#include "../../src/algorithms/MinimumSpanningTree.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::MinimumSpanningTree mst{g1.getGraph()};

	mst.run();
	mst.showResults();

	return 0;
}
