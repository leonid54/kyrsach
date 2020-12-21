#pragma once
#include <iostream>
using namespace std;

class Hall
{
public:
	virtual bool set_and_check_place_morning(int i,int j) = 0;
	virtual bool set_and_check_place_evening(int i, int j) = 0;
protected:
	int m_place[10][20];
	int e_place[10][30];
};