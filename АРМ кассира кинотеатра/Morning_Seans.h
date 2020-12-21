#pragma once
#include <iostream>
using namespace std;
#include "Classic_Hall.h"
#include "Premium_Hall.h"

class Morning_Seans
{
public:
	string set_get_movie(int i);
	string set_get_time(int i);
	string set_get_info(int i);
	void get_price_classic();
	void get_price_premium();
	void save_morning_seans(int i);
private:
	string m_movie[5];
	string m_time[5];
	string m_info[5];
	Chall c;
	Phall p;
};