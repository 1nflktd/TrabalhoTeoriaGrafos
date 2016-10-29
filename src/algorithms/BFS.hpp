#ifndef BFS_HPP
#define BFS_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class BFS : public Algorithm
	{
		int initialVertex;
		void BFSinit();
	public:
		BFS(const Graph & _graph1, int _initialVertex) : Algorithm(_graph1), initialVertex(_initialVertex) {}
		virtual void run();
		virtual void showResults();
		virtual ~BFS() {}
	};
}

#endif