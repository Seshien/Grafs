#include "pch.h"

bool createR(std::vector<std::pair<int, int>> & relations,int nodes)
{
	int node1, node2;
	int check = 1, failsafe=nodes*nodes*nodes;
	if (failsafe < 100) failsafe = 100;
	while (check>0)
	{
		std::cout << "DFS Check: " << check << std::endl;
		check++;
		if (check > failsafe) return 1;
		node1 = rand() % nodes;
		node2 = rand() % nodes;
		if (node1 == node2) continue;
		relations.push_back(std::make_pair(node1, node2));
		if (cycleCheckF(relations))
		{
			relations.pop_back();
			continue;
		}
		check = 0;
	}
	return 0;
}

bool createN(std::vector<std::pair<int, int>> & relations,int node1, int node2)
{
	if (node1 == node2)
	{
		std::cout << "Nie mozna stworzyc takiej relacji" << std::endl;
		return 1;
	}
	relations.push_back(std::make_pair(node1, node2));
	if (cycleCheckF(relations))
	{
		relations.pop_back();
		std::cout << "Relacja psuje graf." << std::endl;
		return 1;
	}
	return 0;
}

//poczatkowy cycleCheck - Szuka wierzcholkow zerowych i dla kazdego z nich odpala cycleChecka
bool cycleCheckF(const std::vector<std::pair<int, int>> & relations)
{
	std::vector<std::pair<int, int>> first = cycleSearch(relations);
	if (first.empty())
		return 1;
	for (auto i : first)
	{
		if (cycleCheck(relations, i))
			return 1;
	}
	return 0;
}

//Rozpoczyna sprawdzanie
bool cycleCheck(const std::vector<std::pair<int, int>> & relations, std::pair<int, int> first)
{

	std::vector<std::pair<int, int>> nSearched; // first to numer liczby, second to pozycja w relations
	std::vector<int> searched;

	nSearched = cycleFind(relations, first.first);
	searched.push_back(first.first);
	if (cycleExist(relations, nSearched, searched))
		return 1;
	for (int i=0;i<nSearched.size();i++)
		if (_cycleCheck(relations, searched, relations[nSearched[i].second]))
			return 1;
	return 0;
}

//Schodzenie nizej
bool _cycleCheck(const std::vector<std::pair<int, int>> & relations, std::vector <int> searched, std::pair<int, int> first)
{
	std::vector<std::pair<int, int>> nSearched; // first to numer liczby, second to pozycja w relations
	if (exCheck(first.second,searched)==0)
		searched.push_back(first.second);
	nSearched=cycleFind(relations, first.second);
	if (cycleExist(relations, nSearched, searched))
		return 1;
	for (int i = 0; i < nSearched.size(); i++)
		if (_cycleCheck(relations, searched, relations[nSearched[i].second]))
			return 1;
	return 0;
}

//Sprawdza czy istnieje juz taka relacja
bool exCheck(int value, const std::vector<int> & searched)
{
	for (size_t i = 0; i < searched.size(); i++)
		if (value == searched[i])
			return 1;
	return 0;
}


//wypisuje wszystkie relacje danego wierzcholka
std::vector<std::pair<int, int>> cycleFind(const std::vector<std::pair<int, int>> & relations, int first)
{
	std::vector<std::pair<int, int>> nSearched;
	for (int i = 0; i < relations.size(); i++)
		if (first == relations[i].first)
			if (!(nSearched.empty()))
			{
				if (nSearched.back().second != i)
					nSearched.push_back(std::make_pair(relations[i].first, i));
			}
			else
				nSearched.push_back(std::make_pair(relations[i].first, i));
	return nSearched;
}

//szuka wierzcholka 0 stopnia oraz sprawdza podstawowe warunki
std::vector<std::pair<int, int>> cycleSearch(const std::vector<std::pair<int, int>> & relations)
{
	std::vector<std::pair<int, int>> first;
	std::vector<std::pair<int, int>> empty;
	bool repeat = 0;
	for (int i = 0; i < relations.size(); i++)
	{
		repeat = 0;
		for (int j = 0; j < relations.size(); j++)
		{
			if (i == j)
				continue;
			if (relations[j] == relations[i])
				return empty;
			if ((relations[j].first == relations[i].second) && (relations[j].second == relations[i].first))
				return empty;
			if (relations[i].first == relations[j].second)
				repeat = 1;
		}
		if (repeat == 0)
		{
			repeat = 0;
			for (int k = 0; k < first.size(); k++)
				if (relations[k].first == relations[i].first)
					repeat = 1;
			if (repeat == 0)
				first.push_back(std::make_pair(relations[i].first, i));
			continue;
		}
	}
	return first;
}

//sprawdza czy istnieje cykl
bool cycleExist(const std::vector<std::pair<int, int>> & relations, const std::vector<std::pair<int, int>> & nSearched, const std::vector <int> & searched)
{
	for (auto i : searched)
		for (auto j : nSearched)
			if (relations[j.second].second == i) return 1;
	return 0;
}

std::vector<std::pair<int, int>> loadGraf(size_t & number)
{
	std::vector<std::pair<int, int>> graf;
	std::ifstream plik;
	std::string filename;
	std::cout << "Prosze podac nazwe pliku" << std::endl;
	std::cin >> filename;
	plik.open(filename, std::ifstream::in);
	if (plik.good() == 0)
	{
		std::cout << "Nie uzyskano dostepu do pliku." << std::endl;
		return graf;
	}
	else
		std::cout << "Dostêp zosta³ uzyskany." << std::endl;
	int n, v, node1, node2;
	plik >> n >> v;
	number = n;
	for (int i = 0; i < v; i++)
	{
		plik >> node1 >> node2;
		if (createN(graf, node1, node2))
		{
			std::cout << "Wystapil blad podczas dodawania krawedzi do grafu" << std::endl;
		}
	}
	return graf;
}

std::vector<std::pair<int, int>> manualGraf(size_t & number)
{
	int num1 = 1, num2 = 2;
	std::vector<std::pair<int, int>> graph;
	std::cout << "Podaj liczbe wierzcholkow." << std::endl;
	std::cin >> number;
	while (1)
	{
		std::cout << "Podaj relacje. By zakonczyc, podaj dwie te same liczby." << std::endl;
		std::cin >> num1 >> num2;
		if (num1 == num2)
			break;
		if (createN(graph, num1, num2))
			std::cout << "Wystapil blad, relacja nie zostala dodana" << std::endl;
	}
	return graph;
}

std::vector<std::pair<int, int>> genGraf(int amount)
{
	std::srand(time(NULL));
	std::vector<std::pair<int, int>> relations;
	int sizeR = amount * (amount - 1) / 2;
	int i = 0;
	while (i < sizeR)
	{
		if (createR(relations, amount))
		{
			i = 0;
			relations.clear();
		}
		else
			i++;
		std::cout << "Relacja " << i << " stworzona. Pozostala ilosc: " << sizeR - i << std::endl;
	}
	showEdges(relations);
	std::cout << "Tworzenie gotowe" << std::endl;
	return relations;
}

void showEdges(const std::vector<std::pair<int, int>> & relations)
{
	for (auto i : relations)
		std::cout << "Relacja " << i.first << " : " << i.second << std::endl;
}