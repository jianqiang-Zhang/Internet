#include "Graph.h"
#include<iostream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF

Graph::Graph()
{
	number = 0;
	matrix = new int*[maxNumber];
	for (int i = 0; i < maxNumber; i++)
	{
		matrix[i] = new int[maxNumber];
		for (int j = 0; j < maxNumber; j++)
		{
			matrix[i][j] = 0;
		}
	}
	hold = new Node[maxNumber];

}

void Graph::AddPoint()
{
	cout << "��ʼ���·����" << endl;
	while (1)
	{
		Node aNew;//һ����·����
		number++;
		aNew.ID = number;
		aNew.edge = new int[number];
		//�½�㵽�����ڵ�ľ���������Ϊmax
		for (int i = 0; i < number; i++)
		{
			aNew.edge[i] = maxDistence;
		}
		aNew.edge[number - 1] = 0;//�Լ����Լ���Ȩ��Ϊ0��		
		//�����ڽӾ���
		for (int i = 0; i < number - 1; i++)
		{
			matrix[i][number - 1] = maxDistence;
			matrix[number - 1][i] = maxDistence;
		}
		cout << "���������·�������ĸ�·��������,����0����" << endl;
		while (1)
		{
			//ѭ���ӱ�
			//int* timeEdge=new int[number];//��ʱ�ıߣ����汻��ӽڵ�
			int heavy = 0;
			int a = 1;//��ʱ�ı���,���汻���ӵ�·�������
			cin >> a;
			if(a==0)
			{
				break;
			}
			cout << "�����������·�����������ڽڵ��Ȩ��" << endl;
			cin >> heavy;
			aNew.edge[a - 1] = heavy;
			
			//ͬʱҲҪ����Ӧ�ı����ӵ�·�����ӱ�
			/*for (int i = 0; i < number - 1; i++)
			{
				timeEdge[i] = hold[a - 1].edge[i];
			}
			timeEdge[number - 1] = heavy;*/
			hold[a - 1].edge[number-1] = heavy;

			//�����ڽӾ���
			matrix[number - 1][number - 1] = 0;
			matrix[number - 1][a - 1] = heavy;
			matrix[a-1][number - 1] = heavy;

		}
		//���´������·����������
		hold[number - 1] = aNew;		
		char judge;
		cout << "�Ƿ���Ҫ������ӱ�(����y����)" << endl;
		cin >> judge;
		if (judge != 'y' && judge != 'Y')
		{
			break;
		}
	}
}


