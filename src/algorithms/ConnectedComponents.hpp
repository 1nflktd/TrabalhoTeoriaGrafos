#ifndef CONNECTED_COMPONENTS_HPP
#define CONNECTED_COMPONENTS_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class ConnectedComponents : public Algorithm
	{
	public:
		ConnectedComponents(const Graph & _graph1) : Algorithm(_graph1) {}
		virtual void run();
		virtual void showResults();
		virtual ~ConnectedComponents() {}
	};
}

#endif