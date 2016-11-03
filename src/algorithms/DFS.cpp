#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

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
	std::vector<int> visited(this->graph.getVertices(), -1);
	std::vector<int> low(this->graph.getVertices(), -1);
	std::vector<int> parent(this->graph.getVertices(), -1);
	std::list<std::pair<int, int>> stack(this->graph.getVertices()); // edges
	int time = 0;
	int nConnectedComponents = 0;
	int nBiconnectedComponents = 0;

	for (int u = 0, count = this->graph.getVertices(); u < count; ++u)
	{
		if (visited[u] == -1)
		{
			this->DFSvisit(u, visited, time, nConnectedComponents++, low, parent, stack, nBiconnectedComponents);
		}

		bool addBiconnectedComponent = false;
		//If stack is not empty, pop all edges from stack
		while (!stack.empty())
		{
			addBiconnectedComponent = true;
			this->graph.addBiconnectedComponent(nBiconnectedComponents, stack.back());
			stack.pop_back();
		}
		if (addBiconnectedComponent) ++nBiconnectedComponents;
	}

	this->graph.setNConnectedComponents(nConnectedComponents);
	this->graph.setNBiconnectedComponents(nBiconnectedComponents);

	for (int i = 0, count = visited.size(); i < count; ++i)
	{
		std::stringstream stream;
		stream << "Vertice " << (i + 1) << ". Ordem de visitacao: " << visited[i] << "\n";
		this->result += stream.str();
	}
}

void algorithms::DFS::DFSvisit(int u, std::vector<int> & visited, int & time, int nConnectedComponents, std::vector<int> & low, std::vector<int> & parent, std::list<std::pair<int, int>> & stack, int & nBiconnectedComponents)
{
	low[u] = visited[u] = ++time;
	int children = 0;

	this->graph.addConnectedComponent(nConnectedComponents, u);
	for (int v = 0, count = this->graph.getVertices(); v < count; ++v)
	{
		if (this->graph(u, v) > 0)
		{
			if (visited[v] == -1)
			{
				++children;
				parent[v] = u;
				stack.push_back(std::make_pair(u, v));

				DFSvisit(v, visited, time, nConnectedComponents, low, parent, stack, nBiconnectedComponents);

				low[u] = std::min(low[u], low[v]);

				//If u is an articulation point,
				//pop all edges from stack till u -- v
				if ((visited[u] == 1 && children > 1) || (visited[u] > 1 && low[v] >= visited[u]))
				{
					while(stack.back().first != u || stack.back().second != v)
					{
						this->graph.addBiconnectedComponent(nBiconnectedComponents, stack.back());
						stack.pop_back();
					}
					this->graph.addBiconnectedComponent(nBiconnectedComponents, stack.back());
					stack.pop_back();
					++nBiconnectedComponents;
				}
			}
			else if (parent[u] != v && visited[v] < low[u]) 
			{
				low[u] = std::min(visited[v], low[u]); // visited[v];
				stack.push_back(std::make_pair(u, v));
			}
		}
	}
}
