#include "pch.h"
#include "GrafRepresentation.h"


GrafRepresentation::GrafRepresentation()
{
}

GrafRepresentation::~GrafRepresentation()
{
}

std::vector<int> GrafRepresentation::DFS_TopologicalSorting(bool log)const
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
			if (this->DFS(x, verticesCol, res, log) == false)
				return std::vector<int>{0};
	}
	std::reverse(res.begin(), res.end());
	return res;
}

bool GrafRepresentation::DFS(int ver, std::map<int, VerticesColor> & verticesCol, std::vector<int>& res, bool log)const
{
	if(log)
		std::cout << "Jestem w v = " << ver << std::endl;
	if (verticesCol[ver] == VerticesColor::grey)
	{
		res = std::vector<int>{ 0 };
		if (log)
			std::cout << "Znaleziono petle" << std::endl;
		return false;
	}
	if (verticesCol[ver] == VerticesColor::black)
		return true;

	verticesCol[ver] = VerticesColor::grey;
	auto neighbours = this->getNeighbours(ver);
	for (auto x : neighbours)
	{
		if (DFS(x, verticesCol, res, log) == false)
			return false;
	}
	verticesCol[ver] = VerticesColor::black;
	res.push_back(ver);
	return true;
}

std::vector<int> GrafRepresentation::DEL_TopologicalSorting(bool log)const
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
	while(1)
	{
		if (del == false)
			break;
		del = false;
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
