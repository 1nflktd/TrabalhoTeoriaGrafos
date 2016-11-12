#include <iostream>
#include <limits>

#include "Functions.hpp"

void functions::readInputClear()
{
	std::cin.clear(); //clear bad input flag
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
	std::cout << "Input inválido. Escreva novamente.\n";
}
