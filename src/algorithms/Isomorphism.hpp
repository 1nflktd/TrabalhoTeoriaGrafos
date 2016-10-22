#ifndef ISOMORPHISM_HPP
#define ISOMORPHISM_HPP

#include "Algorithm.hpp"

namespace algorithms;

class Isomorphism : public Algorithm
{
	Graph graph2;
	bool check();
	void generateAllPermutations();
public:
	Isomorphism(const Graph & graph) : graph2(graph) {}
	virtual void run();
	virtual void showResults();
};

#endif