#ifndef GRAPH_GENERATOR_HPP
#define GRAPH_GENERATOR_HPP

#include "Graph.hpp"

class GraphGenerator
{
	virtual void read() = 0;
protected:
	Graph graph;
public:
	GraphGenerator() {}
	inline Graph getGraph() const { return this->graph; }
	virtual ~GraphGenerator() {}
};

#endif