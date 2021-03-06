#ifndef GRAPH_GENERATOR_FILE_HPP
#define GRAPH_GENERATOR_FILE_HPP

#include <string>

#include "GraphGenerator.hpp"

class GraphGeneratorFile : public GraphGenerator
{
	std::string file;
	virtual void read();
public:
	GraphGeneratorFile(const std::string & _file) : file(_file) { this->read(); }
};

#endif