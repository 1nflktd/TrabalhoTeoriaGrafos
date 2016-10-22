#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#include "Isomorphism.hpp"

void Isomorphism::run()
{
	this->generateAllPermutations();
}

void Isomorphism::showResults()
{
	std::cout << this->result;
}

bool Isomorphism::check(const Graph & graph1, const Graph & graph2, const std::vector<int> & map)
{
	auto N = graph1.getVertices();
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= N; ++j)
			if(graph1(i, j) != graph2(map[i],map[j])) return false;
	return true;
}

void Isomorphism::generateAllPermutations()
{
    std::vector<int> v(this->graph.getVertices());
    std::iota(v.begin(), v.end(), 1);
    do
    {
		if (this->check(this->graph, this->graph2, v)) 
			this->result += "funcao de mapeamento correta!\n";
    } while(std::next_permutation(v.begin(), v.end()));
}
