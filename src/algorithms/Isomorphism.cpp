#include <iostream>

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
	auto N = g1[0].size();
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(g1[i][j] != g2[map[i]][map[j]]) return false;
	return true;
}

void algorithms::Isomorphism::generateAllPermutations()
{
	std::vector<int> F(this->graph.getVertices());

	for (int i = 0; i < N; ++i)
	{
		F[0] = i;
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;
			F[1] = j;
			for (int k = 0; k < N; ++k)
			{
				if (k == i || k == j) continue;
				F[2] = k;
				for (int l = 0; l < N; ++l)
				{
					if (l == i || l == j || l == k) continue;
					F[3] = l;
					if (ver_isomorfismo(this->graph, this->graph2, F)) 
						this->result += "funcao de mapeamento correta! \n";
				}
			}
		}
	}	
}