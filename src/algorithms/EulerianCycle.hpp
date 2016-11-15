#ifndef EULERIAN_CYCLE_HPP
#define EULERIAN_CYCLE_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class EulerianCycle : public Algorithm
	{
	public:
		EulerianCycle(const Graph & _graph1) : Algorithm(_graph1) {}
		virtual void run();
		virtual void showResults();
		virtual ~EulerianCycle() {}
	};
}

#endif