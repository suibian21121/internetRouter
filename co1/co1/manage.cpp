// test.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "����·������" << endl;
		cout << "1��ɾ����" << endl;
		cout << "2��ɾ����" << endl;
		cout << "3������·�ɱ�" << endl;
		cout << "4���˳�" << endl;
		cout << "������ţ�" << endl;
		cin >> x;
		switch (x)
		{
		case 1:DelEdge(); break;
		case 2:DelVertex(); break;
		case 3:show(); break;
		case 4:return; break;
		default:
			cout << "��������" << endl;
			break;
		}
	}
}

void manage::DelEdge()
{
	int v1, v2;
	cout << "������ʼ����" << endl;
	cin >> v1;
	cout << "�����յ���" << endl;
	cin >> v2;
	v1 = g.getvertexpos(v1);
	v2 = g.getvertexpos(v2);
	if (!g.removeEdge(v1, v2))
		cout << "error!" << endl;
}
void manage::DelVertex()
{
	int v;
	cout << "����Ҫɾ�����ı�ţ�" << endl;
	cin >> v;
	v = g.getvertexpos(v);
	if (!g.removeVertex(v))
		cout << "ɾ��ʧ��" << endl;
}

void manage::show()
{
	int v, j, i, n, m, v2;
	int *dist;
	int *path;
	n = g.NumberOfVertices();
	dist = new int[n];
	path = new int[n];
	cout << "�������ţ�����·�ɱ�" << endl;
	cin >> v;
	g.ShortestPath(v, dist, path);
	v2 = g.getvertexpos(v);
	cout << "Ŀ��·��       ��һ��" << endl;
	for (i = 0; i < n; i++)
	{
		m = g.getValue(i);
		if (i == v2) continue;
		j = i;
		if (path[j] == -1 && path[j] != v2)
		{
			cout << m << "                 " << "���ɴ�" << endl;
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