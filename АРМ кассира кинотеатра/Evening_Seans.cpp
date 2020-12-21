#include "Evening_Seans.h"

string Evening_Seans::set_get_movie(int i)
{
	m_movie[0] = "������������";
	m_movie[1] = "��������� �����";
	m_movie[2] = "��������";
	m_movie[3] = "����������� �� �����";
	m_movie[4] = "����";
	return m_movie[i];
}

string Evening_Seans::set_get_time(int i)
{
	m_time[0] = "13:30 - 15:50";
	m_time[1] = "16:00 - 18:30";
	m_time[2] = "18:40 - 20:10";
	m_time[3] = "20:20 - 22:20";
	m_time[4] = "22:30 - 23:55";
	return m_time[i];
}

string Evening_Seans::set_get_info(int i)
{
	m_info[0] = "������";
	m_info[1] = "�������";
	m_info[2] = "�������";
	m_info[3] = "�����";
	m_info[4] = "�������, �����";
	return m_info[i];
}

void Evening_Seans::get_price_classic(){cout << c.get_evening_price();}

void Evening_Seans::get_price_premium() { cout << p.get_evening_price(); }

void Evening_Seans::save_evening_seans(int i)
{
	ofstream fstream("entry.txt", ofstream::app);
	fstream << m_movie[i] << endl;
	fstream << m_info[i] << endl;
	fstream << m_time[i] << endl;
}