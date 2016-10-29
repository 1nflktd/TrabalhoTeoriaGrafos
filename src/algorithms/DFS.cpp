#include <iostream>
#include <vector>
#include <sstream>

#include "DFS.hpp"

void algorithms::DFS::run()
{
	this->DFSinit();
}

void algorithms::DFS::showResults()
{
	std::cout << this->result;
}

void algorithms::DFS::DFSinit()
{
	std::vector<int> vVisited(this->graph.getVertices(), -1);
	int time = 0;
	for (int u = 0, count = this->graph.getVertices(); u < count; ++u)
	{
		if (vVisited[u] == -1)
		{
			this->DFSvisit(u, vVisited, time);
		}
	}

	for (int i = 0, count = vVisited.size(); i < count; ++i)
	{
		std::stringstream stream;
		stream << "vertice " << i << " ordem de visitacao " << vVisited[i] << "\n";
		this->result += stream.str();
	}
}

void algorithms::DFS::DFSvisit(int u, std::vector<int> & vVisited, int & time)
{
	++time;
	vVisited[u] = time;
	for (int v = 0, count = this->graph.getVertices(); v < count; ++v)
	{
		if (this->graph(u, v) > 0 && vVisited[v] == -1)
		{
			DFSvisit(v, vVisited, time);
		}
	}
}
