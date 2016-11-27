#ifndef MINIMUM_SPANNING_TREE_HPP
#define MINIMUM_SPANNING_TREE_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class MinimumSpanningTree : public Algorithm
	{
	public:
		MinimumSpanningTree(const Graph & _graph1) : Algorithm(_graph1) {}
		virtual void run();
		virtual void showResults();
		virtual ~MinimumSpanningTree() {}
	};
}

#endif