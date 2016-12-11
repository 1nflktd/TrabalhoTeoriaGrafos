#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "DFS.hpp"
#include "HamiltonianCycle.hpp"

void algorithms::HamiltonianCycle::run()
{
	VecInt path(this->graph.getVertices(), -1);

	path[0] = 0; // start with 0

	std::stringstream stream;

	if (!this->hamCycle(path, 1)) 
	{
		stream << "Nao ha ciclo hamiltoniano.\n";	
	}
	else
	{
		stream << "Ciclo hamiltoniano:\n";
		for (const auto & v : path)
		{
			stream << (v + 1) << " ";
		}
		stream << path[0] << "\n";
	}

	this->result += stream.str();
}

bool algorithms::HamiltonianCycle::canAccess(int v, const VecInt & path, int pos)
{
	// check if there is an adjacent vertex
	if (this->graph(path[pos-1], v) == -1)
		return false;

	// check if already included
	if (std::find(path.begin(), path.end(), v) != path.end())
		return false;

	return true;
}

bool algorithms::HamiltonianCycle::hamCycle(VecInt & path, int pos)
{
	int vertices = this->graph.getVertices();
	if (vertices == pos) // all vertices included
	{
		if (this->graph(path[pos-1], path[0]) == -1)
			return false;
		return true;
	}

	for (int v = 1; v < vertices; ++v)
	{
		if (this->canAccess(v, path, pos))
		{
			path[pos] = v;

			if (this->hamCycle(path, pos+1))
				return true;

			path[pos] = -1;
		}
	}

	return false;
}

void algorithms::HamiltonianCycle::showResults()
{
	std::cout << this->result;
}
