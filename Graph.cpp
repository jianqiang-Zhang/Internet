#include "Graph.h"
#include<iostream>
#include<fstream>
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
			matrix[i][j] = -1;
		}
	}
	hold = new Node[maxNumber];

}

//���ڴ��е��ڽӾ�����Ϣд���ļ���
void Graph::WriteFile()
{
	//���ڴ��е��ڽӾ�����Ϣд���ļ���
	fstream file("��������.txt", ios::in);
	//�Ƚ��ܵĽ����д���ļ�
	file << number << endl;
	for(int i=0;i<number;i++)
		for (int j = 0; j < i; j++)
		{
			if(matrix[i][j] != 0&& matrix[i][j] != maxDistence)
			file << j<<" ";
			file << i<<" ";
			file << matrix[i][j]<<endl;
		}
	file.close();
}

void Graph::ReadFile()
{
	int head = 0;//һ�ߵ�ͷ��㣨һ����С���Ǹ�Ϊͷ)
	int tail = 0;//һ���ߵ�β�ͽ�㣨һ���Ŵ���Ǹ�Ϊβ�ͣ�
	int heavy = 0;//����ߵ�Ȩ��
	cout << "�������ļ�����һ����������" << endl;
	fstream file("��������.txt", ios::in);
	file >> number;
	//��ʼ����ѭ��д�ڽӾ���
	while (!file.eof())
	{
		file >> head;
		file >> tail;
		file >> heavy;
		matrix[head - 1][tail - 1] = heavy;
		matrix[tail - 1][head - 1] = heavy;
		//���޷��ﵽ����Ϊ������
		for (int i = 0; i < number; i++)
		{
			if (matrix[head - 1][i] == -1)
			{
				matrix[head - 1][i] = maxDistence;
				matrix[i][head - 1] = maxDistence;
			}
			if (matrix[tail - 1][i] == -1)
			{
				matrix[tail - 1][i] = maxDistence;
				matrix[i][tail - 1] = maxDistence;
			}
		}
		matrix[head - 1][head - 1] = 0;
		matrix[tail - 1][tail - 1] = 0;
	}
	file.close();
	//�ٽ��ڽӾ����е�����д����������
	SetNode();
}

void Graph::AddPoint()
{
	cout << "��ʼ���·����" << endl;
	while (1)
	{
		Node aNew;//һ����·����
		number++;
		/*aNew.ID = number;
		aNew.edge = new int[number];
		//�½�㵽�����ڵ�ľ���������Ϊmax
		for (int i = 0; i < number; i++)
		{
			aNew.edge[i] = maxDistence;
		}
		aNew.edge[number - 1] = 0;//�Լ����Լ���Ȩ��Ϊ0��*/		
		//�����ڽӾ���
		for (int i = 0; i < number - 1; i++)
		{
			matrix[i][number - 1] = maxDistence;
			matrix[number - 1][i] = maxDistence;
		}
		while (1)
		{
			//ѭ���ӱ�
			int heavy = 0;
			int a = 1;//��ʱ�ı���,���汻���ӵ�·�������
			cout << "������������Ϊ" << number << "��·�������ĸ�·��������,����0����" << endl;
			cin >> a;
			if(a==0)
			{
				break;
			}
			else if (matrix[a - 1][0] == -1)
			{
				cout << "�����ڶ�Ӧ�Ľ��" << endl;
			}
			else
			{
				cout << "�����������·�����������ڽڵ��Ȩ��" << endl;
				cin >> heavy;
				//ͬʱҲҪ����Ӧ�ı����ӵ�·�����ӱ�
				//�����ڽӾ���
				matrix[number - 1][number - 1] = 0;
				matrix[number - 1][a - 1] = heavy;
				matrix[a - 1][number - 1] = heavy;
				cout << "������" << endl;
			}
		}
		//���´������·����������		
		char judge;
		cout << "�Ƿ���Ҫ��������µ�·����(����y����)" << endl;
		cin >> judge;
		if (judge != 'y' && judge != 'Y')
		{
			break;
		}
	}
	//�ٽ�����·�����е���Ϣͨ���ڽӾ�������ڴ�
	SetNode();
	WriteFile();
}

void Graph::AddEdge()
{
	while (1)
	{
		int head = 0;
		int tail = 0;
		int heavy = 0;
		cout << "��������Ҫ���ӵı�����һͷ��·�������" << endl;
		cin >> head;
		cout << "��������Ҫ���ӵı���һͷ��·�������" << endl;
		cin >> tail;
		cout << "��������Ҫ���ӵıߵ�Ȩ��" << endl;
		cin >> heavy;
		if (head == tail)
			cout << "�����Լ����Լ�������" << endl;
		else if (matrix[head - 1][tail - 1] != maxDistence)
			cout << "�ñ��Ѿ�����" << endl;
		else
		{
			matrix[head - 1][tail - 1] = heavy;
			cout << "������" << endl;
		}
		char judge;
		cout << "�Ƿ���Ҫ�����ӱ�,������n������" << endl;
		cin >> judge;
		if (judge == 'n' || judge == 'N')
			break;
	}
	SetNode();
	WriteFile();
}

void Graph::SetNode()
{
	for (int i = 0; i < number; i++)
	{
		hold[i].ID = i + 1;
		for (int j = 0;j < number; j++)
		{
			hold[i].edge[j] = matrix[i][j];
		}
	}
}

void Graph::DeleteEdge()
{
	while (1)
	{
		int head = 0;
		int tail = 0;
		int heavy = 0;
		cout << "��������Ҫɾ���ı�����һͷ��·�������" << endl;
		cin >> head;
		cout << "��������Ҫɾ���ı���һͷ��·�������" << endl;
		cin >> tail;
		cout << "��������Ҫɾ���ıߵ�Ȩ��" << endl;
		cin >> heavy;
		if (head == tail)
			cout << "�Լ����Լ�֮�䲻��Ҫ·��" << endl;
		else if (matrix[head - 1][tail - 1] == maxDistence)
			cout << "�ñ߲�����" << endl;
		else
		{
			matrix[head - 1][tail - 1] = maxDistence;
			cout << "ɾ�����" << endl;
		}
		char judge;
		cout << "�Ƿ���Ҫ����ɾ����,������n������" << endl;
		cin >> judge;
		if (judge == 'n' || judge == 'N')
			break;
	}
	SetNode();
	WriteFile();
}

void Graph::DeletePoint()
{
	while (1)
	{
		int num=0;
		cout << "��������Ҫɾ����·�������,ɾ�����·�������֮���·������Ž�������ǰһλ" << endl;
		cin >> num;
		//��ʼ��������(��ֱ�ӵ������ڽӾ���)
		//�Ƚ�ÿһ�д���num�������ϵ�һλ
		if (matrix[num - 1][0] == -1)
		{
			cout << "�޸�·��������������ȷ�ı��" << endl;
		}
		else
		{
			for (int i = num - 1; i < number; i++)
				for (int j = num - 1; j < i; j++)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
			//�ٽ�ÿһ�д���num����������Ųһλ
			for (int j = 0; j < number; j++)
				for (int i = num - 1; i < number; i++)
				{
					matrix[i][j] = matrix[i + 1][j];
				}
			//������䵽��������
			for (int i = 0; i < number; i++)
				for (int j = 0; j < i; j++)
				{
					matrix[j][i] = matrix[i][j];
				}
			cout << "ɾ�����"<<endl;
		}
		cout << "�Ƿ���Ҫ����ɾ�����,����n����" << endl;
		char judge;
		cin >> judge;
		if (judge == 'N' || judge == 'n')
		{
			break;
		}

	}
	SetNode();
	WriteFile();
}