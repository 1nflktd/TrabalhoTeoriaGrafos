#include <iostream>

#include "Program.hpp"
#include "GraphGeneratorFile.hpp"
#include "algorithms/Algorithm.hpp"
#include "algorithms/Isomorphism.hpp"
//#include "GraphGeneratorConsole.hpp"

void Program::run()
{
	bool exit = false;
	while(!exit) 
	{
		this->showInitialMenu();
		exit = this->processDataInitialMenu();
	}
}

void Program::showInitialMenu() const
{
	std::cout 
		<< "|-----------------------------------------------------|\n"
		<< "|               Trabalho de grafos                    |\n"
		<< "|-----------------------------------------------------|\n"
		<< "|" << static_cast<char>(Option::A) << "- Identificação de isomorfismo entre dois grafos |\n"
		<< "|" << static_cast<char>(Option::B) << "- Busca em amplitude e profundidade |\n"
		<< "|" << static_cast<char>(Option::Quit) << "- Sair |\n"
		<< "|-----------------------------------------------------|\n"
	;
}

bool Program::processDataInitialMenu()
{
	bool exit = false;
	char option;
	std::cin >> option;
	if (option >= static_cast<char>(Option::A) && option <= static_cast<char>(Option::H))
	{
		this->runInner(static_cast<Option>(option));
	}
	else if (option == static_cast<char>(Option::Quit))
	{
		exit = true;
		std::cout << "Programa encerrado!\n";
	}
	else 
	{
		std::cout << "Opção inválida! Digite novamente.\n";
	}
	return exit;
}

void Program::runInner(Option option)
{
	bool exit = false;
	while (!exit)
	{
		this->showInnerMenu(option);
		int optionInner;
		std::cin >> optionInner;
		if (optionInner == 1 || optionInner == 2)
		{
			this->processDataInnerMenu(option, static_cast<ReadFrom>(optionInner));
		}
		else
		{
			std::cout << "Opção inválida! Digite novamente." << std::endl;
			exit = true;
		}
	}
}

void Program::showInnerMenu(Option option) const
{
	std::cout << "|-----------------------------------------------------|\n";
	if (option == Option::A) 
	{
		std::cout 
			<< "| " << static_cast<int>(ReadFrom::File) << " - Ler 2 arquivos com grafos, separados por espaço |\n"
		    << "| Ex. grafo1.g grafo2.g |\n";
	}
	else
	{
		std::cout << "| " << static_cast<int>(ReadFrom::File) << " - Ler arquivo com grafo Ex. grafo.g |\n";
	}

	std::cout
		<< "| " << static_cast<int>(ReadFrom::Console) << " - Inserir dados no console |\n"
		<< "|-----------------------------------------------------|\n"
	;
}

void Program::processDataInnerMenu(Option option, ReadFrom optionInner)
{
	if (optionInner == ReadFrom::File)
	{
		std::string fileGraph1;
		if (option == Option::A) 
		{
			std::string fileGraph2;
			std::cin >> fileGraph1 >> fileGraph2;

			GraphGeneratorFile graphGenerator1{fileGraph1};
			Graph graph1{graphGenerator1.getGraph()};
			
			GraphGeneratorFile graphGenerator2{fileGraph2};
			Graph graph2{graphGenerator2.getGraph()};

			algorithms::Isomorphism algorithm{graph1, graph2};
		}
		else
		{
			std::cin >> fileGraph1;
			GraphGeneratorFile graphGenerator1{fileGraph1};
		}
	}
	else if (optionInner == ReadFrom::Console)
	{

	}
	else
	{
		std::cout << "Opção inválida.\n";
	}
}
