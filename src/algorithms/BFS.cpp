#include <vector>
#include <queue>
#include <sstream>
#include <iostream>

#include "BFS.hpp"

void algorithms::BFS::run()
{
	this->BFSinit();
}

void algorithms::BFS::showResults()
{
	std::cout << this->result;
}

void algorithms::BFS::BFSinit()
{
	if (this->initialVertex < 0 || this->initialVertex >= this->graph.getVertices()) 
	{
		return; // throw exception
	}
	std::vector<int> vLevel(this->graph.getVertices(), -1);
	vLevel[this->initialVertex] = 0;

	std::queue<int> queue;
	queue.push(this->initialVertex);

	while (!queue.empty())
	{
		int n = queue.front();
		queue.pop();

		for (int a = 0, count = this->graph.getVertices(); a < count; ++a)
		{
			if (this->graph(n,a) > 0 && vLevel[a] == -1) 
			{
				vLevel[a] = vLevel[n] + 1;
				queue.push(a);
			}
		}
	}

	for (int i = 0, count = vLevel.size(); i < count; ++i)
	{
		std::stringstream stream;
		stream << i << " " << vLevel[i] << "\n";
		this->result += stream.str();
	}
}
