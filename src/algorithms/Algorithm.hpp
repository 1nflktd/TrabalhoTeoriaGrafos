#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "../Graph.hpp"

namespace algorithms;

class Algorithm
{
	Graph graph;
protected:
	virtual void run() = 0;
	virtual void showResults() = 0;
	std::string result;
public:
	Algorithm() {}
	virtual ~Algorithm() {}
};

#endif