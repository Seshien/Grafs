#pragma once
#include "GrafRepresentation.h"
class AdjacencyMatriceGraph :
	public GrafRepresentation
{
public:
	AdjacencyMatriceGraph(const std::vector<std::pair<int, int>> & eL, size_t V);
	~AdjacencyMatriceGraph();

	// Inherited via GrafRepresentation
	virtual void show() const override;

private:
	std::vector<std::vector<int>> matrix;

	virtual std::vector<int> getVertices()const override;
	virtual std::vector<int> getNeighbours(int v)const override;


};

