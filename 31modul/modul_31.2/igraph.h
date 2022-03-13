#pragma once

#include <iostream>
#include <vector>

using namespace std;
class IGraph
{
public:
	virtual ~IGraph() {};
	IGraph() {};
	IGraph(IGraph* _oth) {};
	virtual void AddEdge(int from, int to) = 0;
	virtual int VerticesCount() const = 0;
	virtual void GetNextVerices(int vertex, vector<int>& vertices) const = 0;
	virtual void GetPrevVerices(int vertex, vector<int>& vertices) const = 0;
};