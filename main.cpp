#include<iostream>
#include"Graph.h"
#include"Node.h"
using namespace std;

int main()
{
	Graph net;
	net.ReadFile();
	cout << "�������������ˣ���������Ӧ���ѡ����Ҫ�Ĳ���" << endl;
	cout << "1.����·����" << endl;
	cout << "2.���ӱ�" << endl;
	cout << "3.ɾ��·����" << endl;
	cout << "4.ɾ����" << endl;
	cout << "5.���·�ɱ�" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		net.AddPoint();
		break;
	}
	case 2:
	{
		net.AddEdge();
		break;
	}
	case 3:
	{
		net.DeletePoint();
		break;
	}
	case 4:
	{
		net.DeleteEdge();
		break;
	}

	case 5:
	{

		break;
	}

	default:
	{
		cout << "������1-5֮�����" << endl;
		break;
	}
	}



}