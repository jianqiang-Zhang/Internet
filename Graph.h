#pragma once
#include"Node.h"
class Graph
{
public:
	Graph();
	void Create();
	void AddPoint();
	void AddEdge();
	void DeletePoint();
	void DeleteEdge();



private:
	int number;//网络中路由器的个数
	int** matrix;//网络的邻接矩阵
	Node* hold;//作为一个数组用来存放各个节点的信息
};

