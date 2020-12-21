#pragma once
#include <iostream>
using namespace std;
#include "Hall.h"
#include <fstream>
class Chall :public Hall
{
public:
	void set_morning_price();
	void set_evening_price();
	string get_morning_price();
	string get_evening_price();
	void saveToFile_morning();
	void saveToFile_evening();
	bool set_and_check_place_morning(int i, int j) override;
    bool set_and_check_place_evening(int i, int j) override;
private:
	string morning_price = "200 рублей";
	string evening_price = "350 рублей";
};