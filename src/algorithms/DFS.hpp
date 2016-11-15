#ifndef DFS_HPP
#define DFS_HPP

#include <vector>
#include <list>
#include <utility>

#include "Algorithm.hpp"

namespace algorithms
{
	class DFS : public Algorithm
	{
		int initialVertex;
		void DFSinit();
		void DFSvisit(int, VecInt &, int &, int, VecInt &, VecInt &, std::list<std::pair<int, int>> &, int &);
		void doVisit(int, VecInt &, int &, int &, VecInt &, VecInt &, std::list<std::pair<int, int>> &, int &);
	public:
		DFS(const Graph & _graph1, int _initialVertex) : Algorithm(_graph1), initialVertex(_initialVertex) {}
		virtual void run();
		virtual void showResults();
		virtual ~DFS() {}
	};
}

#endif