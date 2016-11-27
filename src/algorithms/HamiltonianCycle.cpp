#include <sstream>
#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <cmath>
#include <limits>

#include "DFS.hpp"
#include "HamiltonianCycle.hpp"

void algorithms::HamiltonianCycle::run()
{
	Matrix table(this->graph.getVertices(), VecInt(std::pow(2, this->graph.getVertices()), -1));
	MatrixList tableList(this->graph.getVertices(), AdjacencyList(std::pow(2, this->graph.getVertices())));

	int C = std::pow(2, this->graph.getVertices()) - 1; // all bits high

	PairList ret = this->hamCycle(0, C, table, tableList);

	std::stringstream stream;
	stream << "Custo total:\n" << ret.first << "\n";

	stream << "Ciclo: \n";
	for (const auto & x : ret.second)
	{
		stream << (x + 1) << " ";
	}
	stream << "\n";

	this->result += stream.str();
}

PairList algorithms::HamiltonianCycle::hamCycle(int i, int C, Matrix & table, MatrixList & tableList) // C mapa de bits
{
	std::list<int> listVertices;

	if (table[i][C] != -1)
	{
		return std::make_pair(table[i][C], tableList[i][C]);
	}

	if (C == 0) 
	{
		listVertices.push_back(0);
		table[i][C] = this->graph(i, 0) == -1 ? 0 : this->graph(i, 0);
		tableList[i][C] = listVertices;

		return std::make_pair(this->graph(i, 0), tableList[i][C]);
	}

	int size = this->graph.getVertices();
	int min = std::numeric_limits<int>::max();

	for (int j = 0; j < size; ++j)
	{
		if (C & (1 << j))
		{
			PairList ret = this->hamCycle(j, C & (~(1 << j)), table, tableList);  // take j out of C
			int w = this->graph(i, j) == -1 ? 0 : this->graph(i, j);
			int aux = w + ret.first;
			if (aux < min) 
			{
				min = aux;
				listVertices = ret.second;
				listVertices.push_back(j);
			}
		}
	}

	table[i][C] = min;
	tableList[i][C] = listVertices;

	return std::make_pair(table[i][C], listVertices);
}

void algorithms::HamiltonianCycle::showResults()
{
	std::cout << this->result;
}
