#include <sstream>
#include <iostream>

#include "DFS.hpp"
#include "HamiltonianCycle.hpp"

void algorithms::HamiltonianCycle::run()
{
	/*

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using VecGrafo = std::vector<std::vector<int>>;

int f(int i, const VecGrafo & grafo, int C, VecGrafo & tab, VecGrafo & grafoAux) // C mapa de bits
{
	if (tab[i][C] != -1)
	{
		return tab[i][C];
	}
	if (C == 0) 
	{
		tab[i][C] = grafo[i][0];
		return grafo[i][0];
	}

	size_t tam = grafo[0].size();
	int min = std::numeric_limits<int>::max();
    int J = -1;
    
	for (int j = 0; j < tam; ++j)
	{
		if (C & (1 << j))
		{
		    int aux = grafo[i][j] + f(j, grafo, C & (~(1 << j)), tab, grafoAux); // tira o j do C
			if (aux < min) 
			{
			    min = aux;
			    J = j;
			}
		}
	}
	
	// 2          4,        8,      14
	// 0010     0100      1000    1110
    // 1          2         3       1
    
    // 1111 - 0
    // 1110 - 1
    // 1100 - 3 - N
    // 1000 - 3
    // 0100 - 2
    // 0010 - 1 - N
    // 0000 - 0
    
    // 1111 - 0
    // 1110 - 2
    // 1100 - 2 - N
    // 1000 - 3
    // 0100 - 2 - N
    // 0010 - 1
    // 0000 - 0
    
	tab[i][C] = min;
    grafoAux[i][C] = J;
    
	return tab[i][C];
}

int main()
{
    // 0 - 1 - 3 - 2 - 0

//	VecGrafo grafo {
//		{0, 2, 10, 7},
//		{20, 0, 9, 1},
//		{1, 5, 0, 15},
//		{7, 12, 3, 0}
//	};

    // 0 - 2 - 3 - 1 - 0
	VecGrafo grafo {
		{0, 10, 2, 7},
		{1, 0, 9, 5},
		{20, 5, 0, 2},
		{7, 3, 12, 0}
	};

	VecGrafo tab(grafo[0].size(), std::vector<int>(std::pow(2, grafo[0].size()), -1));
	VecGrafo grafoAux(grafo[0].size(), std::vector<int>(std::pow(2, grafo[0].size()), -1));

	int C = 15; // 1111
	std::cout << f(0, grafo, C, tab, grafoAux) << "\n";
    
    std::vector<bool> impressos(grafo[0].size(), false);
    for (int i = std::pow(2, grafo[0].size()) - 1; i > 0; --i)
    {
        if (grafoAux[0][i] != -1 && !impressos[grafoAux[0][i]])
        {
            std::cout << grafoAux[0][i] << " ";
            impressos[grafoAux[0][i]] = true;
        }
    }
    std::cout << "0 ";

	return 0;
}
	*/
}

void algorithms::HamiltonianCycle::showResults()
{
	std::cout << this->result;
}
