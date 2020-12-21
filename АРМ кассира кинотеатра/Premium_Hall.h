#pragma once
#include <iostream>
using namespace std;
#include "Hall.h"
#include <fstream>
class Phall : public Hall
{
public:
	void set_morning_price();
	void set_evening_price();
	void saveToFile_morning();
	void saveToFile_evening();
	string get_morning_price();
	string get_evening_price();
	bool set_and_check_place_morning(int i, int j) override;
	bool set_and_check_place_evening(int i, int j) override;
	
private:
	string morning_price = "350 рублей";
	string evening_price = "500 рублей";
};