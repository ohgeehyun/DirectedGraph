#pragma once
#include "Node.h"
#include <iostream> 
using namespace std;

void InputVertex(Graph& graph)
{
	int input;
	cout << "정점(vertex)의 개수를 숫자만 입력 해주세요. \n";
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		Node node(i);
		graph.InputVertex(node);
	}
}

void InputEdge(Graph& graph)
{
	
	cout << "예외 처리가 귀찮아서 존재하지 않는 Vertex접근시 종료됩니다.\n";
	cout << "정점 하나 입력 후 엔터 입력 시 간선 하나가 설정 됩니다.\n";
	cout << "해당 정점의 간선 완료시 -1 입력 시 다음 Vertex로 넘어갑니다.\n";
	for (int i = 0; i < graph.VertexCount(); i++)
	{
		int inputedge = 0;
		cout << i << " 정점의 간선을 입력해주세요.\n";
		while (inputedge>=0)
		{
			cin >> inputedge;
			switch (inputedge)
			{
			case -1:
				break;
			default:
				if (graph.GetVertex(i)._edges->size() >= graph.VertexCount() - 1)
				{
					cout << "이미 모든 간선에 연결되었습니다.";
					continue;
				}
				if (inputedge == i)
				{
					cout << "본인에게 가는 정점은 생성 할 수 없습니다.\n";
					continue;
				}
				if (inputedge > graph.VertexCount() - 1 || inputedge < -1)
				{
					cout << "해당 정점은 없는 정점 입니다.";
					continue;
				}
				if (std::find(graph.GetVertex(i)._edges->begin(), graph.GetVertex(i)._edges->end(), inputedge) != graph.GetVertex(i)._edges->end()) {
					cout << "이미 넣은 간선 입니다.\n";
					continue;
				}

				graph.GetVertex(i)._edges->push_back(inputedge);
				cout << i << " 정점에서 " << inputedge << " 정점으로 간선이 연결 되었습니다.\n";
				break;
			}
		}
	}
}

int InputStartVertex(Graph graph)
{
	int inpputStart;
	while (true)
	{
		cout << "시작할 정점을 입력해주세요.\n";
		cin >> inpputStart;
		if (inpputStart > graph.VertexCount() - 1 || inpputStart < 0)
			cout << "해당 정점은 없는 정점 입니다.";

		break;
	}
	return inpputStart;
}

