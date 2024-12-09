#include <iostream>
#include <Windows.h>
#include <vector>
#include <Stack>
#include <algorithm>
#include "Node.h"
#include "Utils.h"




int main()
{
	SetConsoleOutputCP(CP_UTF8);

	Graph graph;
	InputVertex(graph);
	InputEdge(graph);
	graph.InitDfs();
	graph.Dfs(InputStartVertex(graph));
	graph.visitOrderDfs();
	graph.DeadlockProfiler(InputStartVertex(graph));

	system("pause");
}

