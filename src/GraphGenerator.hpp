#ifndef GRAPH_GENERATOR_HPP
#define GRAPH_GENERATOR_HPP

#include "Graph.hpp"

class GraphGenerator
{
	Graph graph;
	virtual void read() = 0;
public:
	GraphGenerator() {}
	inline Graph generateGraph() const { return this->graph; }
};

#endif