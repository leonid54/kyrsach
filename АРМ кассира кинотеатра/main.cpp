//АРМ кассира кинотеатра
#include <iostream>
#include <string>
#include "hall.h"
#include "Premium_Hall.h"
#include "Classic_Hall.h"
#include "Morning_Seans.h"
#include "Evening_Seans.h"
#include <fstream>
using namespace std;
#include "Entry.h"


void fillParams(string& name, string& surname, string& dataBirth, string& password, string& repeatPassword, string& answer)
{
	cout << "Регистрация нового пользователя:" << endl
		<< "Введите Имя(Подсказка:Имя не должно содержать кириллицу,цифры):";
	cin >> name;

	cout << "Введите Фамилию(Подсказка:Фамилия не должна содержать кириллицу,цифры):";
	cin >> surname;

	cout << "Введите Дату Рождения(пример: 08.03.2001):";
	cin >> dataBirth;

	cout << "Придумайте Пароль(от 5 до 16 знаков):";
	cin >> password;

	cout << "Подтвердите Пароль:";
	cin >> repeatPassword;

	cout << "Регистрация(yes/no)?" << endl;
	cin >> answer;
}


void saveToFile(int number_of_ticket,int row,int place)//Серилизация
{
	ofstream fstream("entry.txt",ofstream::app);
	fstream << number_of_ticket << endl;
	fstream << row << endl;
	fstream << place << endl;
}

int enterCheckNumber(int min, int max) //Проверка и ввод числа
{
	int number = 0;
	string str;
	cin >> str;
	while (str.size() > 2)
	{
		cout << "Чиcло введено неверно!\nПопробуйте снова:";
		cin >> str;
	}

	number = stoi(str);

	while (!(number >= min && number <= max))
	{
		cout << "Чиcло введено неверно!\nПопробуйте снова:";
		cin >> number;
	}

	return number;
}
int main()
{
	setlocale(LC_ALL, "ru");
	Entry entry;
	string name, surname, dataBirth, password, repeatPassword, answer, msg;
	Entry loadedEntry;
	if (loadedEntry.loadFromFile())
	{
		cout << "Хотите войти как: " << loadedEntry.getName() << " " << loadedEntry.getSurname() << "?(yes/no)" << endl;
		cin >> answer;
	}
	if (answer == "no" || !loadedEntry.loadFromFile())
	{
		fillParams(name, surname, dataBirth, password, repeatPassword, answer);

		while (!entry.checkValidatiton(answer, msg))
		{
			cout << msg << endl;
			cin >> answer;
		}
		if (answer == "yes")
		{
			while (!entry.checkSize(name))
			{
				cout << "Имя должно содержать более 1 буквы!(Подсказка:Имя не должно содержать кириллицу)" << endl;
				cout << "Введите Имя:";
				cin >> name;
			}
			while (!entry.isStringAlpha(name))
			{
				cout << "Имя должно содержать только буквы!" << endl;
				cout << "Введите Имя:";
				cin >> name;
			}
			entry.setName(name);
			while (!entry.checkSize(surname))
			{
				cout << "Фамилия должна содержать более 1 буквы!(Подсказка:Фамилия не должна содержать кириллицу)" << endl;
				cout << "Введите Фамилию:";
				cin >> surname;
			}
			while (!entry.isStringAlpha(surname))
			{
				cout << "Фамилия должна содержать только буквы!" << endl;
				cout << "Введите Фамилию:";
				cin >> surname;
			}
			entry.setSurname(surname);
			while (!entry.checkDataBirth(dataBirth))
			{
				cout << "Дата рождения должна содержать 10 чисел(пример: 08.03.2001)" << endl;
				cout << "Введите Дату Рождения:";
				cin >> dataBirth;
			}
			while (!entry.isStringNumber(dataBirth))
			{
				cout << "Дата рождения должна содержать только цифры(пример: 08.03.2001)" << endl;
				cout << "Введите Дату Рождения:";
				cin >> dataBirth;
			}
			entry.setdataBirth(dataBirth);
			while (!entry.checkPassword(password))
			{
				cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
				cout << "Придумайте Пароль:";
				cin >> password;
			}
			while (!entry.checkrepeatPassword(password, repeatPassword))
			{
				cout << "Пароли не совпадают!" << endl;
				cout << "Придумайте Пароль:";
				cin >> password;
				while (!entry.checkPassword(password))
				{
					cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
					cout << "Придумайте Пароль:";
					cin >> password;
				}
				cout << "Подтвердите Пароль:";
				cin >> repeatPassword;
			}
			entry.setPassword(password);
			system("cls");
			cout << "Приветствие" << endl;
		}
		else
		{
			cout << "Отмена регистрации!" << endl;
		}

		entry.saveToFile();
		if (answer == "yes")
		{
			cout << "Войти?(yes/no)" << endl;
			cin >> answer;
			if (answer == "yes")
			{
				cout << "Введите пароль: ";
				cin >> password;
				while (!entry.checkEnterPassword(password))
				{
					cout << "Неверный пароль!" << endl << "Введите пароль: ";
					cin >> password;
				}
				cout << "Добро пожаловать, " << entry.getName() << " " << entry.getSurname() << endl;
			}
			else if (answer == "no")
			{
				cout << "Отмена входа" << endl;
				return 0;
			}
			else
			{
				cout << "Ошибка!Необходимо ввести 'yes' для продолжения, 'no' для выхода!" << endl;
			}

		}
	}

	else if (answer == "yes")
	{
		cout << "Введите пароль: ";
		cin >> password;
		while (password != loadedEntry.getPassword())
		{
			cout << "Неверный пароль!" << endl << "Введите пароль: ";
			cin >> password;
		}
		cout << "Добро пожаловать, " << loadedEntry.getName() << " " << loadedEntry.getSurname() << endl;
	}
	else
	{
		cout << "Ошибка!Необходимо ввести 'yes' для продолжения, 'no' для выхода!" << endl;
	}

	int number_of_type,row, place,film;
	int number_of_ticket = 0;
	answer = "";
	Chall c;
	Phall p;
	Hall *classic = &c;
	Hall *premium = &p;
	Morning_Seans m;
	Evening_Seans e;
	cout << "Добро пожаловать в АРМ кассира кинотеатра!" << endl;

	while (answer != "yes")
	{
		cout << "Выберите сеанс(введите 1 - если выбран Утренний сеанс, 2 - если выбран Вечерний сеанс)" << endl;
		number_of_type = enterCheckNumber(1, 2);
		if (number_of_type == 1)
		{
			cout << "Выберите тип зала(введите 1 - если выбран Классический зал, 2 - если выбран Премиальный зал)" << endl;
			number_of_type = enterCheckNumber(1, 2);
			if (number_of_type == 1)
			{
				cout << "Выбран Утренний сеанс в Классическом зале, цена: "; m.get_price_classic(); cout << endl;
				cout << "Выберите фильм:" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << "№" << i + 1 << "|" << m.set_get_movie(i) << "| |" << m.set_get_info(i) << "| |" << "Продолжительность сеанса: " << m.set_get_time(i) << "|" << endl;
				}
				film = enterCheckNumber(1, 5);
				film--;
				cout << "Введите номер ряда (количество рядов = 10)" << endl;
				row = enterCheckNumber(1, 10);
				cout << "Введите номер места (количество мест в ряду = 20)" << endl;
				place = enterCheckNumber(1, 20);
				while (!classic->set_and_check_place_morning(row, place))
				{
					cout << "Это место уже занято!" << endl;
					cout << "Введите номер ряда (количество рядов = 10)" << endl;
					row = enterCheckNumber(1, 10);
					cout << "Введите номер места (количество мест в ряду = 20)" << endl;
					place = enterCheckNumber(1, 20);
				}
				classic->set_and_check_place_morning(row, place);
				system("cls");
				number_of_ticket++;
				cout << "Билет №" << number_of_ticket << endl;
				cout<< "Утренний сеанс в Классическом зале, цена: "; m.get_price_classic(); cout << endl;
				cout << "Фильм: " << m.set_get_movie(film) << "| |" << m.set_get_info(film) << "| |" << "Продолжительность сеанса: " << m.set_get_time(film) << "|" << endl;
				cout << "Ряд: " << row << " " << "Место: " << place << endl;
				saveToFile(number_of_ticket, row, place);
				c.saveToFile_morning();
				m.save_morning_seans(film);
			}
			else if (number_of_type == 2)
			{
				cout << "Выбран Утренний сеанс в Премиальном зале, цена: "; m.get_price_premium(); cout << endl;
				cout << "Выберите фильм:" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << "№" << i + 1 << " " << m.set_get_movie(i) << "| |" << m.set_get_info(i) << "| |" << "Продолжительность сеанса: " << m.set_get_time(i)<< "|" << endl;
				}
				film = enterCheckNumber(1, 5);
				film--;
				cout << "Введите номер ряда (количество рядов = 10)" << endl;
				row = enterCheckNumber(1, 10);
				cout << "Введите номер места (количество мест в ряду = 20)" << endl;
				place = enterCheckNumber(1, 20);
				while (!premium->set_and_check_place_morning(row, place))
				{
					cout << "Это место уже занято!" << endl;
					cout << "Введите номер ряда (количество рядов = 10)" << endl;
					row = enterCheckNumber(1, 10);
					cout << "Введите номер места (количество мест в ряду = 20)" << endl;
					place = enterCheckNumber(1, 20);
				}
				premium->set_and_check_place_morning(row, place);
				system("cls");
				number_of_ticket++;
				cout << "Билет №" << number_of_ticket << endl;
				cout << "Утренний сеанс в Премиальном зале, цена: "; m.get_price_premium(); cout << endl;
				cout << "Фильм: " << m.set_get_movie(film) << "| |" << m.set_get_info(film) << "| |" << "Продолжительность сеанса: " << m.set_get_time(film) << "|" << endl;
				cout << "Ряд: " << row << " " << "Место: " << place << endl;
				saveToFile(number_of_ticket, row, place);
				p.saveToFile_morning();
				m.save_morning_seans(film);
			}
		}
		else if (number_of_type == 2)
		{
			cout << "Выберите тип зала(введите 1 - если выбран Классический зал, 2 - если выбран Премиальный зал)" << endl;
			number_of_type = enterCheckNumber(1, 2);
			if (number_of_type == 1)
			{
				cout << "Выбран Вечерний сеанс в Классическом зале, цена: "; e.get_price_classic(); cout << endl;
				cout << "Выберите фильм:" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << "№" << i + 1 << " " << e.set_get_movie(i) << "| |" << e.set_get_info(i) << "| |" << "Продолжительность сеанса: " << e.set_get_time(i) << "|" << endl;
				}
				film = enterCheckNumber(1, 5);
				film--;
				cout << "Введите номер ряда (количество рядов = 10)" << endl;
				row = enterCheckNumber(1, 10);
				cout << "Введите номер места (количество мест в ряду = 30)" << endl;
				place = enterCheckNumber(1, 30);
				while (!classic->set_and_check_place_evening(row, place))
				{
					cout << "Это место уже занято!" << endl;
					cout << "Введите номер ряда (количество рядов = 10)" << endl;
					row = enterCheckNumber(1, 10);
					cout << "Введите номер места (количество мест в ряду = 30)" << endl;
					place = enterCheckNumber(1, 30);
				}
				classic->set_and_check_place_evening(row, place);
				system("cls");
				number_of_ticket++;
				cout << "Билет №" << number_of_ticket << endl;
				cout << "Вечерний сеанс в Классическом зале, цена: "; e.get_price_classic(); cout << endl;
				cout << "Фильм: " << e.set_get_movie(film) << "| |" << e.set_get_info(film) << "| |" << "Продолжительность сеанса: " << e.set_get_time(film) << "|" << endl;;
				cout << "Ряд: " << row << " " << "Место: " << place << endl;
				saveToFile(number_of_ticket, row, place);
				c.saveToFile_evening();
				e.save_evening_seans(film);
			}
			else if (number_of_type == 2)
			{
				cout << "Выбран Вечерний сеанс в Премиальном зале, цена: "; e.get_price_premium(); cout << endl;
				cout << "Выберите фильм:" << endl;
				for (int i = 0; i < 5; i++)
				{
					cout << "№" << i + 1 << " " << e.set_get_movie(i) << "| |" << e.set_get_info(i) << "| |" << "Продолжительность сеанса: " << e.set_get_time(i) << "|" << endl;
				}
				film = enterCheckNumber(1, 5);
				film--;
				cout << "Введите номер ряда (количество рядов = 10)" << endl;
				row = enterCheckNumber(1, 10);
				cout << "Введите номер места (количество мест в ряду = 30)" << endl;
				place = enterCheckNumber(1, 30);
				while (!premium->set_and_check_place_evening(row, place))
				{
					cout << "Это место уже занято!" << endl;
					cout << "Введите номер ряда (количество рядов = 10)" << endl;
					row = enterCheckNumber(1, 10);
					cout << "Введите номер места (количество мест в ряду = 30)" << endl;
					place = enterCheckNumber(1, 30);
				}
				premium->set_and_check_place_evening(row, place);
				system("cls");
				number_of_ticket++;
				cout << "Билет №" << number_of_ticket << endl;
				cout << "Вечерний сеанс в Премиальном зале, цена: "; e.get_price_premium(); cout << endl;
				cout << "Фильм: " << e.set_get_movie(film) << "| |" << e.set_get_info(film) << "| |" << "Продолжительность сеанса: " << e.set_get_time(film) << "|" << endl;
				cout << "Ряд: " << row << " " << "Место: " << place << endl;
				saveToFile(number_of_ticket, row, place);
				p.saveToFile_evening();
				e.save_evening_seans(film);
			}
		}
		cout << "Закончить оформление билета?(yes/no): " << " " << endl;
		cin >> answer;
		while (answer != "no" && answer != "yes")
		{
			cout << "Ошибка!Введите ответ заново: ";
			cin >> answer;
		}
	}
	return 0;
}