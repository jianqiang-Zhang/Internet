#pragma once
#include"Node.h"
class Graph
{
public:
	Graph();
	void AddPoint();
	void AddEdge();
	void DeletePoint();
	void DeleteEdge();
	void WriteFile();//���ڴ��е���Ϣд���ļ����ļ���һ������ʾ���������е�·����������
	void ReadFile();//���ļ��е���Ϣ�����ڴ���
	void SetNode();//�����ڽӾ���д����·������ֵ

private:
	int number;//������·�����ĸ���
	int** matrix;//������ڽӾ���,�����ڵĽ����Ӧ������ֵΪ-1
	Node* hold;//��Ϊһ������������Ÿ����ڵ����Ϣ
};

