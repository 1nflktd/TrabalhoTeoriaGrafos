#include <iostream>
#include "../../src/algorithms/EulerianCycle.hpp"
#include "../../src/GraphGeneratorFile.hpp"

int main()
{
	GraphGeneratorFile g1{"graph1.g"};

	std::cout << "graph1\n";
	g1.getGraph().printGraphMatrix();

	algorithms::EulerianCycle eulerianCycle{g1.getGraph()};

	eulerianCycle.run();
	eulerianCycle.showResults();

	return 0;
}
