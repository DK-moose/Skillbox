#include "listgraph.h"

ListGraph::ListGraph()
{
	numVertices = 0;
}

ListGraph::ListGraph(int numVertices)
{
	this->numVertices = numVertices;
	for (int i = 0; i < numVertices; i++)
		lists.push_back(new vector<int> {i + 1});
}

ListGraph::ListGraph(IGraph* _oth)
{
	if (this == _oth)
		return;
	if (this != nullptr)
		this->~ListGraph();
	numVertices = _oth->VerticesCount();
	for (int i = 0; i < numVertices; i++)
	{
		vector<int> list;
		_oth->GetNextVerices(i + 1, list);
		lists.push_back(new vector<int>{ i + 1 });
		for (int j = 0; j < list.size(); j++)
			lists[i]->push_back(list[j]);
	}
}

ListGraph::~ListGraph()
{
	for (int i = 0; i < numVertices; i++)
		delete lists[i];
}

void ListGraph::AddEdge(int from, int to) 
{
	for (int i = 0; i < numVertices; i++)
		if (lists[i]->at(0) == from)
		{
			lists[i]->push_back(to);
			return;
		}

	cout << "This vertices not exists!" << endl;
}

int ListGraph::VerticesCount() const
{
	return numVertices;
}

void ListGraph::GetNextVerices(int vertex, vector<int>& vertices) const
{
	for (int i = 0; i < numVertices; i++)
		if (lists[i]->at(0) == vertex)
		{
			vertices = *lists[i];
			return;
		}

	cout << "Vertex " << vertex << " not exists!" << endl;
}

void ListGraph::GetPrevVerices(int vertex, vector<int>& vertices) const
{
	for (int i = 0; i < numVertices; i++)
		for (int j = 1; j < lists[i]->size(); j++)
		{
			if (lists[i]->at(j) == vertex)
			{
				vertices.push_back(lists[i]->at(0));
			}
		}
	
	if (vertices.size() == 0)
		cout << "Vertex " << vertex << " not exists!" << endl;
}

void ListGraph::PrintGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		cout << lists[i]->at(0);
		for (int j = 1; j < lists[i]->size(); j++)
			cout << " -> " << lists[i]->at(j);
		cout << endl;
	}
}