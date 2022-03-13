#pragma once

#include "igraph.h"
#include "listgraph.h"

class MatrixGraph : public IGraph
{
private:
	int numVertices;
	vector<vector<bool>*> matrix;

public:
	MatrixGraph();
	MatrixGraph(int numVertices);
	MatrixGraph(IGraph* _oth);
	~MatrixGraph();
	void AddEdge(int from, int to);
	int VerticesCount() const;
	void GetNextVerices(int vertex, vector<int>& vertices) const;
	void GetPrevVerices(int vertex, vector<int>& vertices) const;
	void PrintGraph();
};