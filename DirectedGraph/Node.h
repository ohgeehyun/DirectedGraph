#pragma once
#define OUT
#include <Vector>
#include <unordered_map>

using namespace std;

struct Node
{
	Node(int Number) : myVertex(Number) {};
	~Node() {};

	
	int myVertex;
	vector<int>* _edges = new vector<int>;
};

class Graph
{
public:
	void InputVertex(Node node);
	Node GetVertex(OUT Node node,int number);
	Node GetVertex(int index) { return _nodes[index]; }

	int VertexCount() { return _nodes.size();}

	vector<Node> GetVertexs() { return _nodes; }

public:
	void InitDfs();
	void Dfs(int start);
	void visitOrderDfs();
	//역방향간선(싸이클발생)을 찾는 fucntion
	void DeadlockProfiler(int here);
	

private:
	vector<Node> _nodes; //vertex

private:
	//dfs
	vector<bool> visited;
	vector<int> visitOrder;


	vector<int> discoveredOrder;
	int discoverCount = 0;
	vector<bool> finished;
	vector<int> parent;
	
};

