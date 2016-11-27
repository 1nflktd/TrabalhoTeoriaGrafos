#include <sstream>
#include <iostream>

#include "DFS.hpp"
#include "HamiltonianCycle.hpp"

void algorithms::HamiltonianCycle::run()
{
/*
#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <cmath>

using VecGrafo = std::vector<std::vector<int>>;
using Pair = std::pair<int, std::list<int>>;
using VecLista = std::vector<std::vector<std::list<int>>>;

Pair f (int i, const VecGrafo & grafo, int C, VecGrafo & tab, VecLista & tabLista) // C mapa de bits
{
	std::list<int> lista;
	if (tab[i][C] != -1)
	{
		return std::make_pair(tab[i][C], tabLista[i][C]);
	}
	if (C == 0) 
	{
		lista.push_back(0);
		tab[i][C] = grafo[i][0];
		tabLista[i][C] = lista;
		return std::make_pair(grafo[i][0], tabLista[i][C]);
	}

	size_t tam = grafo[0].size();
	int min = 1 << tam;
	for (int j = 0; j < tam; ++j)
	{
		if (C & (1 << j))
		{
			// lista.push_back(j);
			Pair ret = f(j, grafo, C & (~(1 << j)), tab, tabLista);
			int aux = grafo[i][j] + ret.first; // tira o j do C
			if (aux < min) 
			{
				min = aux;
				lista = ret.second;
				lista.push_back(j);
			}
		}
	}

	tab[i][C] = min;
	tabLista[i][C] = lista;
	return std::make_pair(tab[i][C], lista);
}

int main()
{
	// VecGrafo grafo {
	// 	{0, 2, 10, 7},
	// 	{20, 0, 9, 1},
	// 	{1, 5, 0, 15},
	// 	{7, 12, 3, 0}
	// };

	VecGrafo grafo {
	//   0    1     2   3    4    5    6    7    8    9
		{00 , 18 , 61 , 74 , 20 , 99 , 31 , 18 , 28 , 92} , // 0
		{15 , 00 , 31 , 78 , 54 , 87 , 35 , 85 , 32 , 68} , // 1
		{38 , 82 , 00 , 49 , 82 , 70 , 62 , 10 , 46 , 77} , // 2
		{92 , 36 , 66 , 00 , 81 , 95 , 61 , 42 , 52 , 64} , // 3
		{44 , 73 , 32 , 14 , 00 , 70 , 49 , 49 , 25 , 97} , // 4
		{63 , 72 , 63 , 14 , 83 , 00 , 14 , 48 , 35 , 51} , // 5
		{18 , 37 , 11 , 17 , 42 , 14 , 00 , 33 , 13 , 63} , // 6
		{86 , 75 , 25 , 41 , 49 , 51 , 35 , 00 , 47 , 68} , // 7
		{56 , 60 , 16 , 71 , 78 , 10 , 38 , 41 , 00 , 36} , // 8
		{25 , 17 , 15 , 27 , 31 , 17 , 27 , 73 , 53 , 00}   // 9
	//   0    1     2   3    4    5    6    7    8    9
	};

	VecGrafo tab(grafo[0].size(), std::vector<int>(std::pow(2, grafo[0].size()), -1));
	VecLista tabLista(grafo[0].size(), std::vector<std::list<int>>(std::pow(2, grafo[0].size())));

	// int C = 15; // 1111
	int C = std::pow(2, grafo[0].size()) - 1; // 1111111111
	Pair ret = f(0, grafo, C, tab, tabLista);
	std::cout << ret.first << "\n";

	std::cout << "Lista\n";
	for (const auto & x : ret.second)
	{
		std::cout << x << " ";
	}
	std::cout << "\n";

	return 0;
}	*/
}

void algorithms::HamiltonianCycle::showResults()
{
	std::cout << this->result;
}
