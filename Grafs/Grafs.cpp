#include "pch.h"

void wypiszRes(const std::vector<int> & res)
{
	if (res.size() == 0)
	{
		std::cout << "Graf jest cykliczny";
		return;
	}

	std::cout << "Posortowany topologicznie graf:" << std::endl;
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " : ";
	}
	std::cout << std::endl;

}

void test(const GrafRepresentation & g)
{
	std::cout<<"DFS" << std::endl;
	wypiszRes(g.DFS_TopologicalSorting());
	std::cout << "DEL" << std::endl;
	wypiszRes(g.DEL_TopologicalSorting());
}

int main()
{
	/*
    std::cout << "Hello World!\n"; 
	std::vector<std::pair<int, int>> graf = gen(6);
	std::cout << "Hello World!\n";
	for (auto i : graf)
		std::cout << "Relacja " << i.first << " : " << i.second << std::endl;

	*/

	std::vector<std::pair<int, int>> grafTestowy{ {0,2},{1,0},{1,2},{3,0},{3,1},{3,4},{4,1},{4,2},{5,0},{5,4} };

	AdjacencyMatriceGraph macierzSasiedztwa{ grafTestowy, 6 };
	AdjacencyListGraph listaNastepnikow{ grafTestowy, 6 };
	EdgeListGraph listaKrawedzi{ grafTestowy, 6 };

	std::cout << "Test Macierzy Sasiedztwa:" << std::endl;
	test(macierzSasiedztwa);
	std::cout << "Test Listy Następnikow:" << std::endl;
	test(listaNastepnikow);
	std::cout << "Test Listy Krawędzi:" << std::endl;
	test(listaKrawedzi);

}

