#include <iostream>
#include "../../src/GraphGeneratorConsole.hpp"

int main()
{
	GraphGeneratorConsole g1{};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	return 0;
}