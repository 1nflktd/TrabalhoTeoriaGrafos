#ifndef ISOMORPHISM_HPP
#define ISOMORPHISM_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class Isomorphism : public Algorithm
	{
		Graph graph2;
		bool check(const Graph &, const Graph &, const std::vector<int> &);
		void generateAllPermutations();
		void addPermutationResult(std::vector<int>);
	public:
		Isomorphism(const Graph & _graph1, const Graph & _graph2) : Algorithm(_graph1), graph2(_graph2) {}
		virtual void run();
		virtual void showResults();
		virtual ~Isomorphism() {}
	};
}

#endif