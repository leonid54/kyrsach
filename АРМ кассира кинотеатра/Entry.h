#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>


class Entry
{
public:
	Entry();
	bool checkSize(std::string name);
	bool isStringAlpha(const std::string& name);
	bool checkDataBirth(std::string DataBirth);
	bool isStringNumber(const std::string& name);
	bool checkPassword(std::string password);
	bool checkrepeatPassword(std::string password, std::string repeatPassword);
	bool checkValidatiton(std::string& answer, std::string& msg);
	void setName(std::string name);
	void setSurname(std::string surname);
	void setdataBirth(std::string DataBirth);
	void setPassword(std::string password);
	std::string getName();
	std::string getSurname();
	std::string getPassword();
	bool checkEnterPassword(std::string password);
	void saveToFile();
	bool loadFromFile();

private:
	std::string m_name, m_surname, m_dataBirth, m_password, m_repeatPassword;
};
