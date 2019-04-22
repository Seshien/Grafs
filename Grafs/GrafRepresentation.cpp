#include "pch.h"
#include "GrafRepresentation.h"


GrafRepresentation::~GrafRepresentation()
{
}

std::vector<int> GrafRepresentation::DFS_TopologicalSorting()
{
	std::vector<int> res;
	std::map<int, VerticesColor> verticesCol;
	auto v = this->getVertices();
	for (auto x: v)
	{
		verticesCol[x] = VerticesColor::white;
	}
	for (auto x: v)
	{
		if (verticesCol[x] == VerticesColor::white)
			if (this->DFS(v[0], verticesCol, res) == false)
				return std::vector<int>{0};
	}	
	return res;
}

bool GrafRepresentation::DFS(int ver, std::map<int, VerticesColor> & verticesCol, std::vector<int>& res)
{
	if (verticesCol[ver] == VerticesColor::grey)
	{
		res = std::vector<int>{ 0 };
		return false;
	}
	if (verticesCol[ver] == VerticesColor::black)
		return true;

	verticesCol[ver] = VerticesColor::grey;
	auto neighbours = this->getNeighbours(ver);
	for (auto x : neighbours)
	{
		if (DFS(x, verticesCol, res) == false)
			return false;
	}
	verticesCol[ver] = VerticesColor::black;
	res.push_back(ver);
	return true;
}

std::vector<int> GrafRepresentation::DEL_TopologicalSorting()
{
	std::vector<int> res;
	std::map<int, int> vIn;
	auto v = this->getVertices();
	for (auto x : v)
	{
		vIn[x] = 0;
	}
	for (auto x : v)
	{
		for (auto d : this->getNeighbours(x))
			vIn[d]++;
	}

	bool del = true;
	while (del)
	{
		bool del = false;
		auto it = v.begin();
		while (it != v.end())
		{
			if (vIn[*it] == 0)
			{
				del = true;
				for (auto d : this->getNeighbours(*it))
					vIn[d]--;
				res.push_back(*it);
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	if (v.size() > 0)
		return std::vector<int>{0};
	return res;
}
