#include <iostream>
#include "../../src/algorithms/Isomorphism.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};
	GraphGeneratorFile g2{"graph2.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	std::cout << "graph2\n";
	g2.getGraph().printGraphMatrix();

	algorithms::Isomorphism iso{g1.getGraph(), g2.getGraph()};

	iso.run();
	iso.showResults();

	return 0;
}