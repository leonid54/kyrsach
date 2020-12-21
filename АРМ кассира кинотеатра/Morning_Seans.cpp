#include "Morning_Seans.h"

string Morning_Seans::set_get_movie(int i)
{
	m_movie[0] = "1+1";
	m_movie[1] = "��������";
	m_movie[2] = "�������� ��� ������� �������";
	m_movie[3] = "��������� � ��������";
	m_movie[4] = "�������";
	return m_movie[i];
}

string Morning_Seans::set_get_time(int i)
{
	m_time[0] = "00:10 - 02:15";
	m_time[1] = "02:25 - 05:25";
	m_time[2] = "05:35 - 08:05";
	m_time[3] = "08:15 - 10:00";
	m_time[4] = "10:10 - 13:00";
	return m_time[i];
}

string Morning_Seans::set_get_info(int i)
{
	m_info[0] = "�������, �����";
	m_info[1] = "�������";
	m_info[2] = "�����";
	m_info[3] = "����������, �������";
	m_info[4] = "���������";
	return m_info[i];
}

void Morning_Seans::get_price_classic(){ cout << c.get_morning_price(); }

void Morning_Seans::get_price_premium(){ cout << p.get_morning_price(); }

void Morning_Seans::save_morning_seans(int i)
{
	ofstream fstream("entry.txt", ofstream::app);
	fstream << m_movie[i] << endl;
	fstream << m_info[i] << endl;
	fstream << m_time[i] << endl;
}