#include "Graphlnk.h"
#include<iostream>
using namespace std;
int maxweight  = 1000000;

Graphlnk::Graphlnk(int sz)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex[maxVertices];
	if (NodeTable == NULL)
	{
		cout << "存储分配出错！" << endl;
		exit(1);
	}
	for (int i = 0;i<maxVertices;i++)
	{
		NodeTable[i].adj = NULL;
	}
}
int Graphlnk::getvertexpos( int i)
{
	i=getVertexPos(i);
	return i;
}
//template<typename T, typename E>
int  Graphlnk::NumberOfVertices()
{
	return numVertices;
}
//template<class T, class E>
int Graphlnk::getVertexPos(const int vertex)
{
		for (int i = 0;i< numVertices;i++)
			if (NodeTable[i].data == vertex)
				return i;
		return -1;	
}
//template<class T, class E>
int  Graphlnk::getValue(int i)				//取位置为i的顶点中的值
{
	return (i >= 0 && i< numVertices) ? NodeTable[i].data : 0;
};
//template<class T, class E>
Graphlnk::~Graphlnk()
{
	for (int i = 0;i<maxVertices;i++)
	{
		Edge* p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[] NodeTable;
}
//template<class T, class E>
int Graphlnk::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		Edge* p = NodeTable[v].adj;
		if (p != NULL) return p->dest;
	}
	return -1;
}
//template<class T, class E>
int Graphlnk::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge* p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)
		{
			p = p->link;
		}
		if (p != NULL && p->link != NULL)
			return p->link->dest;
	}
	return -1;
}
//template<class T, class E>
int Graphlnk::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge*p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
			return p->cost;
		else return maxweight;
	}
}
//template<class T, class E>
bool Graphlnk::insertVertex(const int vertex)//添加顶点
{
	if (numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}
//template<class T, class E>
bool Graphlnk::removeVertex(const int v)//删除顶点
{
	if (numVertices == 1 || v<0 || v >= numVertices)return false;
	Edge* p, *s, *t;
	int i, k;
	while (NodeTable[v].adj != NULL)
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		while (s != NULL && s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL) NodeTable[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	NodeTable[v].data = NodeTable[numVertices].data;
	p = NodeTable[v].adj = NodeTable[numVertices].adj;
	while (p != NULL)
	{
		s = NodeTable[p->dest].adj;
		while (s != NULL)
			if (s->dest == numVertices) { s->dest = v;break; }
			else s = s->link;
	    p = p->link;
	}
	return true;
}
//template<class T, class E>
bool Graphlnk::insertEdge(int v1, int v2, int cost)
{
	if (v1 >= 0 && v1< numVertices && v2 >= 0 && v2<numVertices)
	{
		Edge* q, *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL) return false;
		p = new Edge;
		q = new Edge;
		p->dest = v2;
		p->cost = cost;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1;
		q->cost = cost;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return false;
}
//template<class T, class E>
bool Graphlnk::removeEdge(int v1,int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge* p = NodeTable[v1].adj, *q = NULL, *s = p;
		while (p != NULL && p->dest != v2)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			if (p == s)
				NodeTable[v1].adj = p->link;
			else
			{
				q->link = p->link;
			}
			delete p;
		}
		else
		{
			return false;
		}
		p = NodeTable[v2].adj;
		q = NULL;
		s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			NodeTable[v2].adj = p->link;
		else
		{
			q->link = p->link;
		}
		delete p;
		return true;
	}
	return false;
}
//template<class T, class E>
const int maxValue = 500000;
void Graphlnk::ShortestPath(int v1, int dist[], int path[])
{//Graph是一个带权有向图，本算法建立一个数组，dist[j],0<=j<n;是当前求到的从顶点v到顶点j的最短路径长度，同时用数组path存放求到的最短路径
	bool *S = new bool[numVertices];
	int i, j, k, v = getVertexPos(v1);
	int w, min;
	for (i = 0; i<numVertices; i++)
	{
		dist[i] = getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] < maxValue)path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i<numVertices-1; i++)
	{
		min = maxValue;
		int u = v;
		for (j = 0; j<numVertices; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k<numVertices; k++)
		{
			w = getWeight(u, k);
			if (S[k] == false && w <maxValue && (dist[u] + w)<dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
}

