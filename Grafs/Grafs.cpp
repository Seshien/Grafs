#include "pch.h"


std::vector<std::pair<int, int>> simpifiedGen(int n)
{
	std::srand(time(NULL));
	AdjacencyMatriceGraph g({}, n);
	size_t i = 0;
	while ( i < (n*(n-1))/4)
	{
		int a = std::rand() % n;
		int b = (std::rand() % (n - a)) + a;
		if(a!=b)
			if (g.addConnection(std::make_pair(a, b)))
				i++;
	}

	auto res =  g.toList();
	std::vector<int> swapVector;
	for (size_t i = 0; i < n; i++)
	{
		int a;
		do
		{
			a = std::rand() % n;
		} while (std::find(std::begin(swapVector), std::end(swapVector), a) != swapVector.end());
		swapVector.push_back(a);
	}

	for (size_t i = 0; i < res.size(); i++)
	{
		res[i].first = swapVector[res[i].first];
		res[i].second = swapVector[res[i].second];

	}

	return res;
}

void fulltest()
{
	std::map<int, std::vector<std::vector<std::pair<int, int>>>> grafs;
	std::cout << "Start of graf generating"<<std::endl;
	std::vector<int> val{ 10,50,100,150,300,500,1000,2000,3000,5000,7000,10000 };
	for (auto x: val)
	{
		std::cout << "Generating 10 grafs with " << x << " vertexes" << std::endl;
		for (size_t i = 0; i < 10; i++)
		{
			grafs[x].push_back(simpifiedGen(x));
		}
	}
	std::cout << "Testy:" << std::endl;
	for (auto x: val)
	{
		std::ofstream file("test_v2_" + std::to_string(x) + ".txt", std::ios::out);
		std::vector< AdjacencyMatriceGraph> macierzeSasiedztwa;
		std::vector< AdjacencyListGraph> listyNastepnikow;
		std::vector< EdgeListGraph > listyKrawedzi;
		for (size_t i = 0; i < 10; i++)
		{
			macierzeSasiedztwa.push_back({grafs[x][i], (size_t)x});
			listyNastepnikow.push_back({ grafs[x][i], (size_t)x });
			listyKrawedzi.push_back({ grafs[x][i], (size_t)x });
		}
		std::cout << "Test 10 macierzy o " << x << " wierzcholkach dla macierzy sasiedztwa DFS"<<std::endl;
		auto start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10; i++)
		{
			macierzeSasiedztwa[i].DFS_TopologicalSorting(false);
		}
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::cout << "Czas trwania: " << elapsed_seconds.count() << "s\n";
		file << "Macierz_sasiedztwa_DFS: " << elapsed_seconds.count() << std::endl;

		std::cout << "Test 10 macierzy o " << x << " wierzcholkach dla macierzy sasiedztwa DEL" << std::endl;
		start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10; i++)
		{
			macierzeSasiedztwa[i].DEL_TopologicalSorting(false);
		}
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Czas trwania: " << elapsed_seconds.count() << "s\n";
		file << "Macierz_sasiedztwa_DEL: " << elapsed_seconds.count() << std::endl;

		std::cout << "Test 10 macierzy o " << x << " wierzcholkach dla listy nastepnikow DFS" << std::endl;
		start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10; i++)
		{
			listyNastepnikow[i].DFS_TopologicalSorting(false);
		}
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Czas trwania: " << elapsed_seconds.count() << "s\n";
		file << "Listy_nastepnikow_DFS: " << elapsed_seconds.count() << std::endl;

		std::cout << "Test 10 macierzy o " << x << " wierzcholkach dla listy nastepnikow DEL" << std::endl;
		start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10; i++)
		{
			listyNastepnikow[i].DEL_TopologicalSorting(false);
		}
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Czas trwania: " << elapsed_seconds.count() << "s\n";
		file << "Listy_nastepnikow_DEL: " << elapsed_seconds.count() << std::endl;

		std::cout << "Test 10 macierzy o " << x << " wierzcholkach dla listy krawedzi DFS" << std::endl;
		start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10; i++)
		{
			listyKrawedzi[i].DFS_TopologicalSorting(false);
		}
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Czas trwania: " << elapsed_seconds.count() << "s\n";
		file << "Listy_krawedzi_DFS: " << elapsed_seconds.count() << std::endl;

		std::cout << "Test 10 macierzy o " << x << " wierzcholkach dla listy krawedzi DEL" << std::endl;
		start = std::chrono::system_clock::now();
		for (size_t i = 0; i < 10; i++)
		{
			listyKrawedzi[i].DEL_TopologicalSorting(false);
		}
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << "Czas trwania: " << elapsed_seconds.count() << "s\n";
		file << "Listy_krawedzi_DEL: " << elapsed_seconds.count() << std::endl;

		file.close();
		
	}

}

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
				graf = simpifiedGen(number);
			}
			else
			{
				std::cout << "Czy chcesz wczytac dane z pliku?[y/n]" << std::endl;
				std::cin >> choice;
				if (choice == 'y')
				{
					graf = loadGraf(number);
					if (graf.empty())
						std::cout << "Wystapil blad, graf nie zostal wczytany." << std::endl;
					else
						showEdges(graf);
				}
				else
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
		std::cout << "Pokaz graf: Jako macierz sasiedztwa[M], jako liste nastepnikow[N], liste krawedzi[K]" << std::endl;
		std::cout << "Usuwanie grafu[u]. Full test[f]. Wyjdz z programu[e]." << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 'f':
			fulltest();
			break;
		case 'M':
			macierzSasiedztwa.show();
			break;
		case 'N':
			listaNastepnikow.show();
			break;
		case 'K':
			listaKrawedzi.show();
			break;
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

