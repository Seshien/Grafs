#pragma once
#include "GrafRepresentation.h"
class AdjacencyListGraph :
	public GrafRepresentation
{
public:
	AdjacencyListGraph(const std::vector<std::pair<int, int>> & eL, size_t V);
	~AdjacencyListGraph();

private:
	std::vector<std::vector<int>> elListo;

	virtual std::vector<int> getVertices()const override;
	virtual std::vector<int> getNeighbours(int v)const override;

};

