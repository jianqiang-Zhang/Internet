#pragma once
class Node
{
public:
	Node();
	friend class Graph;


private:
	int ID;//·�������
	int* edge;//��¼���·�������ڵ�·�����ıߵ�Ȩ�أ���Ϊ���飬�±��ʾ·������ֵ��ʾȨ�ز����ڵ���Ϊ���ֵ
	int* nextJump;//��¼������·���������·���µ���һ��
};

