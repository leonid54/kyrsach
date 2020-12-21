#include "Classic_Hall.h"

string Chall::get_morning_price(){return morning_price;}

string Chall::get_evening_price(){return evening_price;}

bool Chall::set_and_check_place_morning(int i, int j)
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

bool Chall::set_and_check_place_evening(int i, int j)
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

void Chall::set_morning_price(){morning_price = "200 рублей";}

void Chall::set_evening_price(){evening_price = "350 рублей";}

void Chall::saveToFile_morning()
{
	ofstream fstream("entry.txt", ofstream::app);
	fstream << morning_price  << endl;
}
 
void Chall::saveToFile_evening()
{
	ofstream fstream("entry.txt", ofstream::app);
	fstream << evening_price << endl;
}