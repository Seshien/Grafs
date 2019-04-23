#include "pch.h"
#include "EdgeListGraph.h"

EdgeListGraph::EdgeListGraph(const std::vector<std::pair<int, int>>& eL, size_t V)
{
	edges = eL;
	vCount = V;
}

EdgeListGraph::~EdgeListGraph()
{
}

std::vector<int> EdgeListGraph::getVertices()const
{
	std::vector<int> res;
	for (size_t i = 0; i < vCount; i++)
	{
		res.push_back(i);
	}
	return res;
}

std::vector<int> EdgeListGraph::getNeighbours(int v)const
{
	std::vector<int> res;
	for (auto connection: edges)
	{
		if (connection.first == v)
			res.push_back(connection.second);
	}
	return res;
}
