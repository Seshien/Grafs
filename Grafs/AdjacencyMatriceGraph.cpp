#include "pch.h"
#include "AdjacencyMatriceGraph.h"


AdjacencyMatriceGraph::AdjacencyMatriceGraph(const std::vector<std::pair<int, int>>& eL, size_t V)
{
	matrix.resize(V);
	for (auto &x : matrix)
	{
		x.resize(V);
	}

	for (auto connection : eL)
	{
		matrix[connection.first][connection.second] = 1;
		matrix[connection.second][connection.first] = -1;
	}
}

AdjacencyMatriceGraph::~AdjacencyMatriceGraph()
{
}

std::vector<int> AdjacencyMatriceGraph::getVertices()const
{
	std::vector<int> res;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		res.push_back(i);
	}
	return res;
}

std::vector<int> AdjacencyMatriceGraph::getNeighbours(int v)const
{
	std::vector<int> res;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		if (matrix[v][i] == 1)
			res.push_back(i);
	}
	return res;
}