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

//将内存中的邻接矩阵信息写入文件中
void Graph::WriteFile()
{
	//将内存中的邻接矩阵信息写入文件中
	fstream file("网络拓扑.txt", ios::in);
	//先将总的结点数写入文件
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
	int head = 0;//一边的头结点（一般编号小的那个为头)
	int tail = 0;//一个边的尾巴结点（一般编号大的那个为尾巴）
	int heavy = 0;//这个边的权重
	cout << "先利用文件创建一个网络拓扑" << endl;
	fstream file("网络拓扑.txt", ios::in);
	file >> number;
	//开始利用循环写邻接矩阵
	while (!file.eof())
	{
		file >> head;
		file >> tail;
		file >> heavy;
		matrix[head - 1][tail - 1] = heavy;
		matrix[tail - 1][head - 1] = heavy;
		//将无法达到的置为最大距离
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
	//再将邻接矩阵中的内容写入各个结点中
	SetNode();
}

void Graph::AddPoint()
{
	cout << "开始添加路由器" << endl;
	while (1)
	{
		Node aNew;//一个新路由器
		number++;
		/*aNew.ID = number;
		aNew.edge = new int[number];
		//新结点到各个节点的距离先设置为max
		for (int i = 0; i < number; i++)
		{
			aNew.edge[i] = maxDistence;
		}
		aNew.edge[number - 1] = 0;//自己到自己的权重为0；*/		
		//更新邻接矩阵
		for (int i = 0; i < number - 1; i++)
		{
			matrix[i][number - 1] = maxDistence;
			matrix[number - 1][i] = maxDistence;
		}
		while (1)
		{
			//循环加边
			int heavy = 0;
			int a = 1;//临时的变量,保存被连接的路由器编号
			cout << "请输入这个编号为" << number << "的路由器和哪个路由器相连,输入0结束" << endl;
			cin >> a;
			if(a==0)
			{
				break;
			}
			else if (matrix[a - 1][0] == -1)
			{
				cout << "不存在对应的结点" << endl;
			}
			else
			{
				cout << "请输入这个新路由器到该相邻节点的权重" << endl;
				cin >> heavy;
				//同时也要给相应的被连接的路由器加边
				//更新邻接矩阵
				matrix[number - 1][number - 1] = 0;
				matrix[number - 1][a - 1] = heavy;
				matrix[a - 1][number - 1] = heavy;
				cout << "添加完成" << endl;
			}
		}
		//更新存放所有路由器的数组		
		char judge;
		cout << "是否需要继续添加新的路由器(输入y继续)" << endl;
		cin >> judge;
		if (judge != 'y' && judge != 'Y')
		{
			break;
		}
	}
	//再将各个路由器中的信息通过邻接矩阵存入内存
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
		cout << "请输入需要增加的边其中一头的路由器编号" << endl;
		cin >> head;
		cout << "请输入需要增加的边另一头的路由器编号" << endl;
		cin >> tail;
		cout << "请输入需要增加的边的权重" << endl;
		cin >> heavy;
		if (head == tail)
			cout << "不能自己将自己连起来" << endl;
		else if (matrix[head - 1][tail - 1] != maxDistence)
			cout << "该边已经存在" << endl;
		else
		{
			matrix[head - 1][tail - 1] = heavy;
			cout << "添加完成" << endl;
		}
		char judge;
		cout << "是否需要继续加边,（输入n结束）" << endl;
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
		cout << "请输入需要删除的边其中一头的路由器编号" << endl;
		cin >> head;
		cout << "请输入需要删除的边另一头的路由器编号" << endl;
		cin >> tail;
		cout << "请输入需要删除的边的权重" << endl;
		cin >> heavy;
		if (head == tail)
			cout << "自己与自己之间不需要路径" << endl;
		else if (matrix[head - 1][tail - 1] == maxDistence)
			cout << "该边不存在" << endl;
		else
		{
			matrix[head - 1][tail - 1] = maxDistence;
			cout << "删除完成" << endl;
		}
		char judge;
		cout << "是否需要继续删除边,（输入n结束）" << endl;
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
		cout << "请输入需要删除的路由器编号,删除后该路由器编号之后的路由器编号将依次提前一位" << endl;
		cin >> num;
		//开始调整矩阵(先直接调整下邻接矩阵)
		//先将每一列大于num的依次上调一位
		if (matrix[num - 1][0] == -1)
		{
			cout << "无该路由器，请输入正确的编号" << endl;
		}
		else
		{
			for (int i = num - 1; i < number; i++)
				for (int j = num - 1; j < i; j++)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
			//再将每一行大于num的依次向左挪一位
			for (int j = 0; j < number; j++)
				for (int i = num - 1; i < number; i++)
				{
					matrix[i][j] = matrix[i + 1][j];
				}
			//最后扩充到整个矩阵
			for (int i = 0; i < number; i++)
				for (int j = 0; j < i; j++)
				{
					matrix[j][i] = matrix[i][j];
				}
			cout << "删除完成"<<endl;
		}
		cout << "是否需要继续删除结点,输入n结束" << endl;
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