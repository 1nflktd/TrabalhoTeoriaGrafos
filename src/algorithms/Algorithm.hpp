#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <string>
#include "../Graph.hpp"

namespace algorithms
{
	class Algorithm
	{
	protected:
		virtual void run() = 0;
		virtual void showResults() = 0;
		std::string result;
		Graph graph;
	public:
		Algorithm(const Graph & _graph) : graph(_graph) {}
		virtual ~Algorithm() {}
	};
}

#endif