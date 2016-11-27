#include <sstream>
#include <iostream>
#include <iterator>
#include <memory>

#include "DFS.hpp"
#include "EulerianCycle.hpp"

// based on
// http://algs4.cs.princeton.edu/42digraph/DirectedEulerianCycle.java.html
// http://algs4.cs.princeton.edu/41graph/EulerianCycle.java.html

void algorithms::EulerianCycle::run()
{
	if (this->graph.getEdges() == 0) return; // throw exception ?

	bool directed = this->graph.getValued(); // use valued as directed

	if (directed) 
	{
		if (!this->checkEulerianCycleDirected()) 
		{
			this->result += "Nao ha ciclo euleriano\n";
			return; // throw exception ?
		}
	} 
	else 
	{
		if (!this->checkEulerianCycleUndirected()) 
		{
			this->result += "Nao ha ciclo euleriano\n";
			return; // throw exception ?
		}
	}

	std::stack<int> cycle = directed ? this->getEulerianCycleDirected() : this->getEulerianCycleUndirected();

	int nEdges = directed ? this->graph.getEdges() : this->graph.getEdges()/2;

	if (static_cast<int>(cycle.size()) == nEdges + 1)
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

std::stack<int> algorithms::EulerianCycle::getEulerianCycleDirected()
{
	std::vector<ListInt::iterator> adj(this->graph.getVertices());
	AdjacencyList adjacencyList{this->graph.getAdjacencyList()};

	for (int v = 0; v < this->graph.getVertices(); ++v)
	{
		adj[v] = adjacencyList[v].begin();
	}

	int s = this->graph.getNonIsolatedVertexDirected(); 

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

	return cycle;
}

std::stack<int> algorithms::EulerianCycle::getEulerianCycleUndirected()
{
	int size = this->graph.getVertices();
	std::vector<std::list<std::shared_ptr<Edge>>> adj(size);

	for (int v = 0; v < size; ++v)
	{
		int selfLoops = 0;
		for (const auto & w : this->graph.getAdjacencyList(v))
		{
			if (v == w)
			{
				if (selfLoops % 2 == 0)
				{
					auto e = std::make_shared<Edge>(v, w);
					adj[v].push_back(e);
					adj[w].push_back(e);
				}
				++selfLoops;
			}
			else if (v < w)
			{
				auto e = std::make_shared<Edge>(v, w);
				adj[v].push_back(e);
				adj[w].push_back(e);
			}
		}
	}

	int s = this->graph.getNonIsolatedVertexUndirected();

	std::stack<int> stack;
	stack.push(s);

	std::stack<int> cycle;
	while (!stack.empty())
	{
		int v = stack.top();
		stack.pop();
		while (!adj[v].empty())
		{
			auto edge = adj[v].back();
			adj[v].pop_back();
			if (edge->isUsed) continue;
			edge->isUsed = true;
			stack.push(v);
			v = edge->getOther(v);
		}
		cycle.push(v);
	}

	return cycle;
}

void algorithms::EulerianCycle::showResults()
{
	std::cout << this->result;
}

bool algorithms::EulerianCycle::checkEulerianCycleDirected() const
{
	for (int v = 0; v < this->graph.getVertices(); ++v)
	{
		if (this->graph.getOutdegree(v) != this->graph.getIndegree(v))
			return false;
	}
	return true;
}

bool algorithms::EulerianCycle::checkEulerianCycleUndirected() const
{
	for (int v = 0; v < this->graph.getVertices(); ++v)
	{
		if (this->graph.getDegree(v) % 2 != 0)
			return false;
	}
	return true;
}
