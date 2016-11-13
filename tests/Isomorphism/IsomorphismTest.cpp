#include <iostream>
#include "../../src/algorithms/Isomorphism.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "insira o nome dos grafos como parametros\n";
		return 0;
	}

	GraphGeneratorFile g1{argv[1]};
	GraphGeneratorFile g2{argv[2]};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	std::cout << "graph2\n";
	g2.getGraph().printGraphMatrix();

	algorithms::Isomorphism iso{g1.getGraph(), g2.getGraph()};

	iso.run();
	iso.showResults();

	return 0;
}