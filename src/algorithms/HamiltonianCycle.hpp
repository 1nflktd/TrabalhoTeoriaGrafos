#ifndef HAMILTONIAN_CYCLE_HPP
#define HAMILTONIAN_CYCLE_HPP

#include "Algorithm.hpp"

namespace algorithms
{
	class HamiltonianCycle : public Algorithm
	{
	PairList hamCycle(int, int, Matrix &, MatrixList &); // C mapa de bits
	public:
		HamiltonianCycle(const Graph & _graph1) : Algorithm(_graph1) {}
		virtual void run();
		virtual void showResults();
		virtual ~HamiltonianCycle() {}
	};
}

#endif