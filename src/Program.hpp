#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Graph.hpp"

enum class Option
{
	A = 'a', B, C, D, E, F, G, H, Quit = 'q'
};

enum class ReadFrom
{
	File = 1, Console
};

const int maxWidth = 60;

class Program
{
	void showInitialMenu() const;
	bool processDataInitialMenu();
	void showInnerMenu(Option) const;
	void processDataInnerMenu(Option, ReadFrom);
	void processDataFromFile(Option);
	void processDataFromConsole(Option);
	void runInner(Option);
	void runAlgorithm(Option, const Graph &, const Graph &);
	void runAlgorithm(Option, const Graph &);
public:
	Program() {}
	void run();
};

#endif