#pragma once
#include "pch.h"
class GrafRepresentation
{
public:
	enum class VerticesColor {
		white, grey, black
	};

	GrafRepresentation();
	~GrafRepresentation();

	std::vector<int> DFS_TopologicalSorting(bool log = true)const;

	std::vector<int> DEL_TopologicalSorting(bool log = true)const;

	virtual void show()const = 0;

private:

	bool DFS(int ver, std::map<int, VerticesColor> & verticesCol, std::vector<int>& res, bool log)const;

	virtual std::vector<int> getVertices()const = 0;

	virtual std::vector<int> getNeighbours(int v)const = 0;

};

