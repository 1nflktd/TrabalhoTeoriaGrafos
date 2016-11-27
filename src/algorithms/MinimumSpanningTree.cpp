#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

#include "MinimumSpanningTree.hpp"

void algorithms::MinimumSpanningTree::run()
{
	// prim algorithm

    int totalVertices = this->graph.getVertices();

    VecInt weights(totalVertices, std::numeric_limits<int>::max()); // init weights with +inf
    
    int totalWeight = 0;
    int initialVertex = 0;

    // init initial vertex weights
    for (int i = 0; i < totalVertices; ++i)
    {
        if (this->graph(initialVertex, i) != -1)
        {
            weights[i] = this->graph(initialVertex, i);
        }
    }
    
    VecInt U;
    U.push_back(initialVertex);
    int u = initialVertex;

    while (static_cast<int>(U.size()) != totalVertices) // while not all vertices are in U
    {
        // achar menor valor em l (pesos)
        int minimumValue = std::numeric_limits<int>::max(); 
        int v = 0;

        for (int i = 0; i < totalVertices; ++i)
        {
            if (std::find(U.begin(), U.end(), i) == U.end())
            {
                if (weights[i] < minimumValue)
                {
                    minimumValue = weights[i];
                    v = i;
                }
            }
        }
        
        totalWeight += minimumValue;

        u = v;
        U.push_back(u);
        if (static_cast<int>(U.size()) == totalVertices) break;
        
        // For each v adjacent to u, v ∈ V − U, l(v) <- Min {l(v), cost(u, v)}
        for (int v = 0; v < totalVertices; ++v)
        {
            if (this->graph(u, v) != -1)
            {
                if (std::find(U.begin(), U.end(), v) == U.end())
                {
                    if (weights[v] > this->graph(u, v))
                    {
                        weights[v] = this->graph(u, v);
                    }
                }
            }
        }
    }

    std::stringstream stream;
    stream << "Peso total: " << totalWeight << "\n";
    stream << "Arvore geradora minima\n";
    for (const auto & u : U) 
    {
    	stream << (u + 1) << " ";
    }

    stream << "\n";

    this->result += stream.str();
}

void algorithms::MinimumSpanningTree::showResults()
{
	std::cout << this->result;
}
