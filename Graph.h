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
	int number;//������·�����ĸ���
	int** matrix;//������ڽӾ���
	Node* hold;//��Ϊһ������������Ÿ����ڵ����Ϣ
};

