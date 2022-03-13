#include "matrixgraph.h"

MatrixGraph::MatrixGraph()
{
	numVertices = 0;
}

MatrixGraph::MatrixGraph(int numVertices)
{
	this->numVertices = numVertices;
	for (int i = 0; i < numVertices; i++)
		matrix.push_back(new vector<bool>(numVertices));
}

MatrixGraph::MatrixGraph(IGraph* _oth)
{
	if (this == _oth)
		return;
	if (this != nullptr)
		this->~MatrixGraph();
	numVertices = _oth->VerticesCount();
	for (int i = 0; i < numVertices; i++)
	{
		matrix.push_back(new vector<bool>(numVertices));
		vector<int> list;
		_oth->GetNextVerices(i + 1, list);
		for (int j = 0; j < numVertices; j++)
			for (int k = 1; k < list.size(); k++)
				if (j + 1 == list[k])
					matrix[i]->at(j) = true;
	}
}

MatrixGraph::~MatrixGraph()
{
	for (int i = 0; i < numVertices; i++)
		delete matrix[i];
}

void MatrixGraph::AddEdge(int from, int to)
{
	if (from < 1 || from > numVertices || to < 1 || to > numVertices)
	{
		cout << "This vertices not exists!" << endl;
		return;
	}	
	matrix[from]->at(to) == true;
}

int MatrixGraph::VerticesCount() const
{
	return numVertices;
}

void MatrixGraph::GetNextVerices(int vertex, vector<int>& vertices) const
{
	if (vertex < 1 || vertex > numVertices)
	{
		cout << "Vertex " << vertex << " not exists!" << endl;
		return;
	}
	vertices.clear();
	for (int i = 0; i < numVertices; i++)
	{
		if (matrix[vertex]->at(i) == true)
			vertices.push_back(i + 1);
	}
}

void MatrixGraph::GetPrevVerices(int vertex, vector<int>& vertices) const
{
	if (vertex < 1 || vertex > numVertices)
	{
		cout << "Vertex " << vertex << " not exists!" << endl;
		return;
	}
	vertices.clear();
	for (int i = 0; i < numVertices; i++)
	{
		if (matrix[i]->at(vertex) == true)
			vertices.push_back(i + 1);
	}
}

void MatrixGraph::PrintGraph()
{
	for (int i = 0; i < numVertices; i++)
		cout << "\t" << i + 1;
	cout << endl;
	for (int i = 0; i < numVertices; i++)
	{
		cout << i + 1;
		for (int j = 0; j < numVertices; j++)
		{
			if (matrix[i]->at(j))
				cout << "\t" << 1;
			else cout << "\t" << 0;
		}
		cout << endl;
	}
}