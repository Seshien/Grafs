#pragma once
#include "pch.h"
class GrafRepresentation
{
public:
	enum class VerticesColor {
		white, grey, black
	};

	GrafRepresentation(const std::vector<std::pair<int, int>> & eL);
	~GrafRepresentation();

	std::vector<int> DFS_TopologicalSorting();

	bool DFS(int ver, std::map<int, VerticesColor> & verticesCol, std::vector<int>& res);

	std::vector<int> DEL_TopologicalSorting();

private:

	virtual std::vector<int> getVertices() = 0;

	virtual std::vector<int> getNeighbours(int v) = 0;
};

