#ifndef GRAPH_GENERATOR_CONSOLE_HPP
#define GRAPH_GENERATOR_CONSOLE_HPP

#include "GraphGenerator.hpp"

class GraphGeneratorConsole : public GraphGenerator
{
	virtual void read();
public:
	GraphGeneratorConsole() { this->read(); }
};

#endif