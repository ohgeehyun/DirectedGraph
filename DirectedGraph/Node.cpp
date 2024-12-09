#include "Node.h"
#include <Stack>
#include <iostream>
void Graph::InputVertex(Node node)
{
	_nodes.push_back(node);
}

Node Graph::GetVertex(OUT Node node , int number)
{
	// TODO :혹시나 인덱스  벗어나거나 수정 할 일 있으면 인덱스 검사 추가
	node = _nodes[number];
	return node;
}

void Graph::InitDfs()
{
	visited.resize(_nodes.size(),false);
	finished.resize(_nodes.size(), false);
	parent.resize(_nodes.size(), -1);
	discoveredOrder.resize(_nodes.size(), -1);
}

void Graph::Dfs(int start)
{
	visited[start] = true;
	visitOrder.push_back(start);

	for (const int& vertex : *_nodes[start]._edges) {
		if (!visited[vertex]) {
			Dfs(vertex);
		}
	}
}

void Graph::visitOrderDfs()
{
	for (int i = 0; i < visitOrder.size(); i++)
	{
		if (i == visitOrder.size() - 1)
			cout << visitOrder[i] << '\n';
		else
			cout << visitOrder[i] << " -> ";
	}
}

void Graph::DeadlockProfiler(int here)
{
	//방문이 된적이 있는지 체크
	if (discoveredOrder[here] != -1)
		return;

	//해당 정점의 방문 순서를 기록
	discoveredOrder[here] = discoverCount++;

	//해당 정점이 갈 수 있는 간선 체크
	if (_nodes[here]._edges->size() == 0)
	{
		//가지고 있는 간선이 없음.
		finished[here] = true;
		return;
	}

	//위에서 간선이 있는지 체크 했기때문에 무조건 간선이 하나 이상 있음.
	for (const int& edge : *_nodes[here]._edges)
	{
		//방문한 적이 없는 정점
		if (discoveredOrder[edge] == -1)
		{
			parent[edge] = here;
			DeadlockProfiler(edge);
			continue;
		}
		//이미 방문한 적이 있는 정점 here가 edge보다 작다면 edge는 here의 후손 순방향
		if (discoveredOrder[here] < discoveredOrder[edge])
			continue;
		//순방향이 아니고 DFS가 종료되지않은상태라면 edge는 here의 선조
		if (finished[edge] == false)
		{
			printf("%d -> %d\n",here,edge);

			int now = here;
			while (true)
			{
				printf("%d -> %d\n", parent[now], now);
				now = parent[now];
				if (now == edge)
					break;
			}
		}
		cout << "DEADLOCK_DECTED\n";
	}
	finished[here] = true;
}



