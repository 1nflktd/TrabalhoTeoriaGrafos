#ifndef PROGRAM_HPP
#define PROGRAM_HPP

enum class Option
{
	A = 'a', B, C, D, E, F, G, H, Quit = 'q'
};

enum class ReadFrom
{
	File = 1, Console
};

class Program
{
	void showInitialMenu() const;
	bool processDataInitialMenu();
	void showInnerMenu(Option) const;
	void processDataInnerMenu(Option, ReadFrom);
	void runInner(Option);
public:
	Program() {}
	void run();
};

#endif