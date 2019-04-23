#include "pch.h"

std::vector<std::pair<int, int>> gen(int amount)
{
	std::srand(time(NULL));
	std::vector<std::pair<int, int>> relations;
	int sizeR = amount * (amount - 1) / 2;
	for (int i = 0; i < sizeR; i++)
	{
		createR(relations,amount);
		std::cout << "Relacja " << i + 1 << " stworzona. Pozostala ilosc: " << sizeR - (i + 1) << std::endl;
	}
	for (auto i : relations)
		std::cout << "Relacja " << i.first << " : " << i.second << std::endl;
	std::cout << "Tworzenie gotowe" << std::endl;
	return relations;
}
void createR(std::vector<std::pair<int, int>> & relations,int nodes)
{
	int node1, node2;
	bool check = 0;
	while (check==0)
	{
		check = 0;
		node1 = rand() % nodes;
		node2 = rand() % nodes;
		if (node1 == node2) continue;
		//if (!(relations.empty()))
			//if (exCheck(std::make_pair(node1, node2), relations)) continue;

		relations.push_back(std::make_pair(node1, node2));
		//std::cout << "DFS Check" << std::endl;
		if (cycleCheckF(relations))
		{
			relations.pop_back();
			continue;
		}
		check = 1;
	}

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
//Sprawdza czy istnieje juz taka relacja
bool exCheck(int value, const std::vector<int> & searched)
{
	for (int i = 0; i < searched.size(); i++)
		if (value == searched[i])
			return 1;
	return 0;
}
//poczatkowy cycleCheck - Szuka wierzcholkow zerowych i dla kazdego z nich odpala cycleChecka
bool cycleCheckF(const std::vector<std::pair<int, int>> & relations)
{
	//znajdujemy  wierzcholek bez rodzicow
	std::vector<std::pair<int, int>> first = cycleSearch(relations);
	if (first.empty())
	{
		//std::cout << "Nie mozna bylo znalezc wiercholka zerowego lub znaleziono krotka petle/multigraf." << std::endl;
		return 1;
	}
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
//szuka wierzcholka 0 stopnia
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

	//if (first.empty())
		//std::cout << "Something broken" << std::endl;
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

std::vector<std::pair<int, int>> loadGraf()
{
	std::vector<std::pair<int, int>> graf;
	std::fstream plik;
	std::
	std::cout << "Prosze podac nazwe pliku" << std::endl;

}