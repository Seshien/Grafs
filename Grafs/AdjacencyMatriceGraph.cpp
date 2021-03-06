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

void AdjacencyMatriceGraph::show() const
{
	std::cout << "Graf jako macierz sasiedztwa: " << std::endl;
	std::cout << "-\t";
	for (size_t i = 0; i < matrix.size(); i++)
		std::cout <<i<< "\t";
	std::cout<<std::endl;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		std::cout << i << "\t";
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout<<std::endl;
	}
	std::cout << std::endl;
}

bool AdjacencyMatriceGraph::addConnection(const std::pair<int, int>& c)
{
	if (matrix[c.first][c.second] != 0)
		return false;

	matrix[c.first][c.second] = 1;
	matrix[c.second][c.first] = -1;
	return true;
}


std::vector<std::pair<int, int>> AdjacencyMatriceGraph::toList()
{
	std::vector<std::pair<int, int>> res;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == 1)
				res.push_back(std::make_pair(i, j));
		}
	}
	return res;
}
