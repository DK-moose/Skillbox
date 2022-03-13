#include <iostream>
#include "igraph.h"
#include "listgraph.h"
#include "matrixgraph.h"

using namespace std;

int main()
{
	ListGraph* graph = new ListGraph(4);
	graph->AddEdge(1, 2);
	graph->AddEdge(1, 4);
	graph->AddEdge(2, 3);
	graph->AddEdge(3, 1);
	graph->AddEdge(3, 2);
	graph->AddEdge(4, 3);
	graph->PrintGraph();
	MatrixGraph* copyGraph = new MatrixGraph(graph);
	copyGraph->PrintGraph();
	return 0;
}
