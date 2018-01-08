#pragma once
#include<iostream>
using namespace std;
#include"Graphlnk.h"
#include "input.h"
//template<typename T, typename E>
class manage
{
public:
	manage();
	~manage();
	void menu();
	void DelEdge();
	void DelVertex();
	void show();
protected:
	Graphlnk g;
};