#include <iostream>
#include "../../src/algorithms/BFS.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::BFS bfs{g1.getGraph(), 0};

	bfs.run();
	bfs.showResults();

	return 0;
}