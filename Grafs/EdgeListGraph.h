#pragma once
#include "GrafRepresentation.h"
class EdgeListGraph :
	public GrafRepresentation
{
public:
	EdgeListGraph(const std::vector<std::pair<int, int>>& eL, size_t V);
	~EdgeListGraph();

	// Inherited via GrafRepresentation
	virtual void show() const override;

private:
	size_t vCount;
	std::vector<std::pair<int, int>> edges;

	virtual std::vector<int> getVertices()const override;
	virtual std::vector<int> getNeighbours(int v)const override;

};

