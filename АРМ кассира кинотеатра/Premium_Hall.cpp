#include "Premium_Hall.h"

string Phall::get_morning_price(){return morning_price;}

string Phall::get_evening_price(){return evening_price;}

bool Phall::set_and_check_place_morning(int i, int j)
{
	if (m_place[i][j] == true)
	{
		return false;
	}
	else if (m_place[i][j] != true && m_place[i][j] != false)
	{
		m_place[i][j] = true;
	}
	return true;
}

bool Phall::set_and_check_place_evening(int i, int j)
{
	if (e_place[i][j] == true)
	{
		return false;
	}
	else if (e_place[i][j] != true && e_place[i][j] != false)
	{
		e_place[i][j] = true;
	}
	return true;
}

void Phall::set_morning_price(){morning_price = "350 рублей";}

void Phall::set_evening_price(){ evening_price = "500 рублей"; }

void Phall::saveToFile_morning()
{
	ofstream fstream("entry.txt", ofstream::app);
	fstream << morning_price << endl;
}

void Phall::saveToFile_evening()
{
	ofstream fstream("entry.txt", ofstream::app);
	fstream << evening_price << endl;
}