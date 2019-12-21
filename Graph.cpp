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
	cout << "开始添加路由器" << endl;
	while (1)
	{
		Node aNew;//一个新路由器
		number++;
		aNew.ID = number;
		aNew.edge = new int[number];
		//新结点到各个节点的距离先设置为max
		for (int i = 0; i < number; i++)
		{
			aNew.edge[i] = maxDistence;
		}
		aNew.edge[number - 1] = 0;//自己到自己的权重为0；		
		//更新邻接矩阵
		for (int i = 0; i < number - 1; i++)
		{
			matrix[i][number - 1] = maxDistence;
			matrix[number - 1][i] = maxDistence;
		}
		cout << "请输入这个路由器和哪个路由器相连,输入0结束" << endl;
		while (1)
		{
			//循环加边
			//int* timeEdge=new int[number];//临时的边，保存被添加节点
			int heavy = 0;
			int a = 1;//临时的变量,保存被连接的路由器编号
			cin >> a;
			if(a==0)
			{
				break;
			}
			cout << "请输入这个新路由器到该相邻节点的权重" << endl;
			cin >> heavy;
			aNew.edge[a - 1] = heavy;
			
			//同时也要给相应的被连接的路由器加边
			/*for (int i = 0; i < number - 1; i++)
			{
				timeEdge[i] = hold[a - 1].edge[i];
			}
			timeEdge[number - 1] = heavy;*/
			hold[a - 1].edge[number-1] = heavy;

			//更新邻接矩阵
			matrix[number - 1][number - 1] = 0;
			matrix[number - 1][a - 1] = heavy;
			matrix[a-1][number - 1] = heavy;

		}
		//更新存放所有路由器的数组
		hold[number - 1] = aNew;		
		char judge;
		cout << "是否需要继续添加边(输入y继续)" << endl;
		cin >> judge;
		if (judge != 'y' && judge != 'Y')
		{
			break;
		}
	}
}


