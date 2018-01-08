#ifndef GRAPHLNK_H
#define GRAPHLNK_H
#include<vector>
//template<typename T, typename E>
struct Edge
{
	int dest;//下一个站点编号
	int cost;//两站间的距离
	Edge *link;//下一条边链指针
};
//template<typename T, typename E>
struct Vertex
{
	int data;          //站点编号
	Edge *adj;			//边链表的头指针
	Vertex():adj(NULL){};
};
const int DeafultVertices = 30;			//代表最大顶点数 =n
//template<typename T, typename E>
class Graphlnk
{
public:
	Graphlnk(int sz = DeafultVertices);
	~Graphlnk();
	int getValue(int i);					//取位置为i的顶点中的值
	int getWeight(int v1, int v2);			//返回边(v1,v2)的权值
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