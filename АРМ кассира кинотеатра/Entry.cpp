#include "Entry.h"
#pragma once
using namespace std;
Entry::Entry()
{

}
bool Entry::checkSize(string name)
{
	return(name.size() >= 2);
}

bool Entry::isStringAlpha(const string& name)
{
	if (name.empty())
	{
		return false;
	}
	for (int i = 0; i < name.size(); i++)
	{
		if (!isalpha(name[i]))
		{
			return false;
		}
	}
	return true;
}
bool Entry::checkDataBirth(string DataBirth)
{
	if (DataBirth.size() < 10)
	{
		return false;
	}
	else if (DataBirth.size() > 10)
	{
		return false;
	}
	return true;
}

bool Entry::isStringNumber(const string& name)
{
	if (name.empty())
	{
		return false;
	}
	for (int i = 0; i < name.size(); i++)
	{
		if (isalpha(name[i]) && name[i] != '.')
		{
			return false;
		}
	}
	return true;
}

bool Entry::checkPassword(string password)
{
	if (password.size() < 5)
	{
		return false;
	}
	else if (password.size() > 15)
	{
		return false;
	}
	return true;
}

bool Entry::checkrepeatPassword(string password, string repeatPassword)
{
	return(password == repeatPassword);
}
bool Entry::checkValidatiton(string& answer, string& msg)
{
	if (answer != "yes" && answer != "no")
	{
		msg = "Необходимо ввести 'yes' для продолжения, 'no' для выхода!";
		return false;
	}
	return true;
}

void Entry::setName(string name)
{
	m_name = name;
}
void Entry::setSurname(string surname)
{
	m_surname = surname;
}
void Entry::setdataBirth(string DataBirth)
{
	m_dataBirth = DataBirth;
}
void Entry::setPassword(string password)
{
	m_password = password;
}
string Entry::getName()
{
	return m_name;
}
string Entry::getSurname()
{
	return m_surname;
}
string Entry::getPassword()
{
	return m_password;
}

bool Entry::checkEnterPassword(string password)
{
	return(password == m_password);
}
void Entry::saveToFile()
{
	ofstream fstream("entry.txt");
	fstream << m_name << endl;
	fstream << m_surname << endl;
	fstream << m_password << endl;
}
bool Entry::loadFromFile()
{
	ifstream fstream("entry.txt");
	if (!fstream.is_open()) return false;
	getline(fstream, m_name);
	getline(fstream, m_surname);
	getline(fstream, m_password);
	return true;
}
