#ifndef EULERIAN_CYCLE_HPP
#define EULERIAN_CYCLE_HPP

#include "Algorithm.hpp"

#include <stack>

namespace algorithms
{
	struct Edge
	{
		int v;
		int w;
		bool isUsed;
		Edge(int _v, int _w) : v(_v), w(_w), isUsed(false) {}
		inline int getOther(int vertex) { return vertex == v ? w : v; }
	};

	class EulerianCycle : public Algorithm
	{
	bool checkEulerianCycleDirected() const;
	bool checkEulerianCycleUndirected() const;
	std::stack<int> getEulerianCycleDirected();
	std::stack<int> getEulerianCycleUndirected();
	public:
		EulerianCycle(const Graph & _graph1) : Algorithm(_graph1) {}
		virtual void run();
		virtual void showResults();
		virtual ~EulerianCycle() {}
	};
}

#endif