#include "pch.h"
#include "AdjacencyListGraph.h"

AdjacencyListGraph::AdjacencyListGraph(const std::vector<std::pair<int, int>>& eL, size_t V)
{
	elListo.resize(V);

	for (auto connection : eL)
	{
		elListo[connection.first].push_back(connection.second);
	}
}

AdjacencyListGraph::~AdjacencyListGraph()
{
}

std::vector<int> AdjacencyListGraph::getVertices()const
{
	std::vector<int> res;
	for (size_t i = 0; i < elListo.size(); i++)
	{
		res.push_back(i);
	}
	return res;
}

std::vector<int> AdjacencyListGraph::getNeighbours(int v)const
{
	return elListo[v];
}

void AdjacencyListGraph::show() const
{
	std::cout << "Graf jak list sasiedztwa:" << std::endl;
	for (size_t i = 0; i < elListo.size(); i++)
	{
		std::cout << i << ":\t";
		for (size_t j = 0; j < elListo[i].size(); j++)
		{
			std::cout << elListo[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
