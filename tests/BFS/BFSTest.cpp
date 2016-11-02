#include <iostream>
#include "../../src/algorithms/BFS.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	int initialVertex = 1; // read from console
	algorithms::BFS bfs{g1.getGraph(), --initialVertex};

	bfs.run();
	bfs.showResults();

	return 0;
}
