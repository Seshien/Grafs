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
