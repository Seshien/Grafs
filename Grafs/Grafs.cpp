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
std::vector<std::pair<int, int>> manualGraf(size_t & number)
{
	int num1 = 1, num2 = 2;
	std::vector<std::pair<int, int>> graph;
	while (1)
	{
		std::cout << "Podaj relacje. By zakonczyc, podaj dwie te same liczby." << std::endl;
		std::cin >> num1 >> num2;
		if (num1 == num2)
			break;
		if (createN(graph, num1, num2))
			std::cout << "Wystapil blad, relacja nie zostala dodana" << std::endl;
	}
	number = graph.size();
	return graph;
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
	std::cout << "Witamy w programie symulujacym grafy." << std::endl;
	std::vector<std::pair<int, int>> graf;
	size_t number;
	char choice = 'c';
	while (choice != 'e')
	{
		while (graf.empty())
		{
			std::cout << "Musisz utworzyc graf na ktorym chcesz pracowac. Czy chcesz uzyc generatora?[y/n]" << std::endl;
			std::cin >> choice;
			if (choice == 'y')
			{
				std::cout << "Prosze podac ilosc wierzcholkow." << std::endl;
				std::cin >> number;
				graf = gen(number);
			}
			else
			{
				graf = manualGraf(number);
			}
		}
		AdjacencyMatriceGraph macierzSasiedztwa{ graf, number };
		AdjacencyListGraph listaNastepnikow{ graf, number };
		EdgeListGraph listaKrawedzi{ graf, number };
		std::cout << "<-------------------------------------------------------------->" << std::endl;
		std::cout << "Graf istnieje. Wybierz czynnosc z listy." << std::endl;
		std::cout << "<-------------------------------------------------------------->" << std::endl;
		std::cout << "Test: Dla macierzy sasiedztwa[m], dla listy nastepnikow[n], listy krawedzi[k]." << std::endl;
		std::cout << "Usuwanie grafu[u]. Full test[f]. Wyjdz z programu[e]." << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 'm':
			//AdjacencyMatriceGraph macierzSasiedztwa{ graf, number };
			std::cout << "Test Macierzy Sasiedztwa:" << std::endl;
			test(macierzSasiedztwa);
			break;
		case 'n':
			//AdjacencyListGraph listaNastepnikow{ graf, number };
			std::cout << "Test Listy Następnikow:" << std::endl;
			test(listaNastepnikow);
			break;
		case 'k':
			//EdgeListGraph listaKrawedzi{ graf, number };
			std::cout << "Test Listy Krawędzi:" << std::endl;
			test(listaKrawedzi);
			break;
		case 'e':
			std::cout << "Wychodzenie z programu." << std::endl;
			break;
		case 'u':
			std::cout << "Usuwanie grafu." << std::endl;
			graf.clear();
			break;
		default:
			std::cout << "Komenda nie rozpoznana." << std::endl;
		}
		std::cout << "<-------------------------------------------------------------->" << std::endl;
	}
	







}

