#pragma once

#include "igraph.h"
#include "matrixgraph.h"

class ListGraph : public IGraph
{
private:
	int numVertices;
	vector<vector<int>*> lists;

public:
	ListGraph();
	ListGraph(int numVertices);
	ListGraph(IGraph* _oth);
	~ListGraph();
	void AddEdge(int from, int to);
	int VerticesCount() const;
	void GetNextVerices(int vertex, vector<int>& vertices) const;
	void GetPrevVerices(int vertex, vector<int>& vertices) const;
	void PrintGraph();
};