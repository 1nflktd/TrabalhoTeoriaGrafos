#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace Algorithms;

class Algorithm
{
	
protected:
	virtual void run() = 0;
	virtual void showResults() = 0;
public:
	Algorithm() {}
	virtual ~Algorithm() {}
};

#endif