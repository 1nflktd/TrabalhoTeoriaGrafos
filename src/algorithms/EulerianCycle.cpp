#include <sstream>
#include <iostream>
#include <stack>
#include <iterator>

#include "DFS.hpp"
#include "EulerianCycle.hpp"

// http://algs4.cs.princeton.edu/42digraph/
// http://algs4.cs.princeton.edu/42digraph/DirectedEulerianCycle.java.html
// http://algs4.cs.princeton.edu/41graph/EulerianCycle.java.html

void algorithms::EulerianCycle::run()
{
	// directed eulerian cycle

	if (this->graph.getEdges() == 0) return; // throw exception ?

	for (int v = 0; v < this->graph.getVertices(); ++v)
	{
		if (this->graph.getOutdegree(v) != this->graph.getIndegree(v))
			return; // throw exception ?
	}

	std::vector<ListInt::iterator> adj(this->graph.getVertices());
	AdjacencyList adjacencyList{this->graph.getAdjacencyList()};

	for (int v = 0; v < this->graph.getVertices(); ++v)
	{
		adj[v] = adjacencyList[v].begin();
	}

	int s = this->graph.getNonIsolatedVertex();

	std::stack<int> stack;
	stack.push(s);

	std::stack<int> cycle;
	while (!stack.empty())
	{
		int v = stack.top();
		stack.pop();

		while (adj[v] != adjacencyList[v].end())
		{
			stack.push(v);
			v = *adj[v]++;
		}

		cycle.push(v);
	}

	if (static_cast<int>(cycle.size()) == this->graph.getEdges() + 1)
	{
		this->result += "Ciclo euleriano:\n";
		while (!cycle.empty())
		{
			int v = cycle.top();
			cycle.pop();

			std::stringstream stream;
			stream << (v + 1) << " ";
			this->result += stream.str(); // vertices from 1
		}
		this->result += "\n";
	}
	else
	{
		this->result += "Nao ha ciclo euleriano\n";
	}
}

void algorithms::EulerianCycle::showResults()
{
	std::cout << this->result;
}
