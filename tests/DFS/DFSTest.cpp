#include <iostream>
#include "../../src/algorithms/DFS.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::DFS dfs{g1.getGraph(), 0};

	dfs.run();
	dfs.showResults();

	return 0;
}