#include "pch.h"

int main()
{

    std::cout << "Hello World!\n"; 
	std::vector<std::pair<int, int>> graf = gen(50);
	std::cout << "Hello World!\n";
	for (auto i : graf)
		std::cout << "Relacja " << i.first << " : " << i.second << std::endl;
}

