#ifndef GRAPHLNK_H
#define GRAPHLNK_H
#include<vector>
//template<typename T, typename E>
struct Edge
{
	int dest;//��һ��վ����
	int cost;//��վ��ľ���
	Edge *link;//��һ������ָ��
};
//template<typename T, typename E>
struct Vertex
{
	int data;          //վ����
	Edge *adj;			//�������ͷָ��
	Vertex():adj(NULL){};
};
const int DeafultVertices = 30;			//������󶥵��� =n
//template<typename T, typename E>
class Graphlnk
{
public:
	Graphlnk(int sz = DeafultVertices);
	~Graphlnk();
	int getValue(int i);					//ȡλ��Ϊi�Ķ����е�ֵ
	int getWeight(int v1, int v2);			//���ر�(v1,v2)��Ȩֵ
	bool insertVertex(const int vertex);
	bool removeVertex(int v);
	bool insertEdge(int v1, int v2, int cost);
	bool removeEdge(int v1, int v2);
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	int NumberOfVertices();
	int getvertexpos(int i);
	void ShortestPath(int v1, int dist[], int path[]);
protected:
	Vertex * NodeTable;
	int numEdges;
	int numVertices;
	int maxVertices;
	int getVertexPos(const int vertex);
};
#endif