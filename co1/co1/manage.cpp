// test.cpp : 定义控制台应用程序的入口点。
//
#include"manage.h"
#include"Graphlnk.h"
using namespace std;
manage::manage()
{
	input(&g);
}
manage::~manage()
{
}
void manage::menu()
{
	while (1)
	{
		int x;
		cout << "网络路由生成" << endl;
		cout << "1、删除边" << endl;
		cout << "2、删除点" << endl;
		cout << "3、生成路由表" << endl;
		cout << "4、退出" << endl;
		cout << "输入点编号：" << endl;
		cin >> x;
		switch (x)
		{
		case 1:DelEdge(); break;
		case 2:DelVertex(); break;
		case 3:show(); break;
		case 4:return; break;
		default:
			cout << "输入有误！" << endl;
			break;
		}
	}
}

void manage::DelEdge()
{
	int v1, v2;
	cout << "输入起始点编号" << endl;
	cin >> v1;
	cout << "输入终点编号" << endl;
	cin >> v2;
	v1 = g.getvertexpos(v1);
	v2 = g.getvertexpos(v2);
	if (!g.removeEdge(v1, v2))
		cout << "error!" << endl;
}
void manage::DelVertex()
{
	int v;
	cout << "输入要删除结点的编号：" << endl;
	cin >> v;
	v = g.getvertexpos(v);
	if (!g.removeVertex(v))
		cout << "删除失败" << endl;
}

void manage::show()
{
	int v, j, i, n, m, v2;
	int *dist;
	int *path;
	n = g.NumberOfVertices();
	dist = new int[n];
	path = new int[n];
	cout << "输入结点编号，生成路由表" << endl;
	cin >> v;
	g.ShortestPath(v, dist, path);
	v2 = g.getvertexpos(v);
	cout << "目的路由       下一跳" << endl;
	for (i = 0; i < n; i++)
	{
		m = g.getValue(i);
		if (i == v2) continue;
		j = i;
		if (path[j] == -1 && path[j] != v2)
		{
			cout << m << "                 " << "不可达" << endl;
			continue;
		}
		if (path[j] == v2)
		{
			cout << m << "                 " << m << endl;
		}
		else
		{
			while (path[j] != v2)
			{
				j = path[j];
			}
			cout << m << "                 " << j + 1 << endl;
		}
	}
}