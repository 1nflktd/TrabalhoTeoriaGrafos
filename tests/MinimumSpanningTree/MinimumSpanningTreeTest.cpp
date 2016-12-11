#include <iostream>
#include "../../src/algorithms/MinimumSpanningTree.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "<nome do grafo>\n";
		return 0;
	}

	GraphGeneratorFile g1{argv[1]};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::MinimumSpanningTree mst{g1.getGraph()};

	mst.run();
	mst.showResults();

	return 0;
}
