#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Graphlnk.h"
using namespace std;
//template<class T, class E>
int input(void * a) {
	Graphlnk & g = *(Graphlnk *)a;
	fstream s;
	s.open("Router.txt",ios::in);
	char buffer[1024];
	int v, tv,se,sv;
	int w;
	s.getline(buffer, 1024);
	stringstream ss(buffer);
		ss >> v;
	while (ss) {
		g.insertVertex(v);
		ss >> v;
	}
	s.getline(buffer, 1024);
	ss.clear();
	ss.str(buffer);
	ss >> v;
	for (;s.good();) 
	{
		se = g.getvertexpos(v);
		ss >> tv;
		ss >> w;
		while (ss)
		{
			sv = g.getvertexpos(tv);
			g.insertEdge(se, sv, w);
			ss >> tv;
			ss >> w;
		}
		s.getline(buffer, 1024);
		ss.str(buffer);
		ss.clear();
		ss >> v;
	};
	return 0;
};