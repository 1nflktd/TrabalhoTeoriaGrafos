#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "Isomorphism.hpp"

void algorithms::Isomorphism::run()
{
	this->generateAllPermutations();
}

void algorithms::Isomorphism::showResults()
{
	std::cout << this->result;
}

bool algorithms::Isomorphism::check(const Graph & graph1, const Graph & graph2, const std::vector<int> & map)
{
	auto N = graph1.getVertices();
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(graph1(i, j) != graph2(map[i], map[j])) return false;
	return true;
}

void algorithms::Isomorphism::generateAllPermutations()
{
    std::vector<int> v(this->graph.getVertices());
    std::iota(v.begin(), v.end(), 0); // 0, 1, 2, 3, up to N
    bool found = false;
    do
    {
 		if (this->check(this->graph, this->graph2, v)) 
		{
			addPermutationResult(v);
			found = true;
		}
    } while(std::next_permutation(v.begin(), v.end()));

    if (!found)
    {
    	this->result += "Grafos não são isomorfos.\n";
    }
}

void algorithms::Isomorphism::addPermutationResult(std::vector<int> map)
{
    std::transform(map.begin(), map.end(), map.begin(), [](int a) { return a + 1; }); // print vertex from 1 .. to N, not 0
	std::stringstream result;
	std::copy(map.begin(), map.end(), std::ostream_iterator<int>(result, " "));
	this->result += "Mapeamento correto: " + result.str() + "\n";
}
