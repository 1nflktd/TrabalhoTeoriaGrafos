#ifndef BICONNECTED_COMPONENTS_HPP
#define BICONNECTED_COMPONENTS_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class BiconnectedComponents : public Algorithm
	{
	public:
		BiconnectedComponents(const Graph & _graph1) : Algorithm(_graph1) {}
		virtual void run();
		virtual void showResults();
		virtual ~BiconnectedComponents() {}
	};
}

#endif