#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <map>
using namespace std;

void save(multimap<string, string> d)
{
	ofstream save;          
	multimap<string, string>::iterator i;
	save.open("dict.txt"); 
	if (save.is_open())
	{
		for (i = d.begin(); i != d.end(); i++)
		{
			save << i->first << endl;
			save << i->second << endl;
		}
	}
	save.close();
}

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	multimap<string, string> dictionary;
	multimap<string, string>::iterator i, res;
	int n;
	string st1, st2;
	int menu = 0, menu2 = 0;

	ifstream load("dict.txt");
	if (load.is_open())
	{
		while (getline(load, st1) && getline(load, st2))
		{
			dictionary.insert(pair<string, string>(st1, st2));
		}
	}
	load.close();

	do
	{
		system("cls");
		cout << "=======================" << endl;
		cout << "\tАнгло-Русский словарь" << endl;
		cout << "1::Найти слово" << endl;
		cout << "2::Добавить слово / Добавить перевод" << endl;
		cout << "3::Удалить слово" << endl;
		cout << "4::Редактировать преревод" << endl;
		cout << "0::Exit" << endl;
		cout << "=======================\n" << endl;
		cout << ">>";
		cin >> menu;



		switch (menu)
		{
		case 0: break;
		case 1:
			cout << "Введите слово (на английском) >>\n";
			cin.get(); getline(cin, st1);
			res = dictionary.find(st1);
			if (res == dictionary.end())
			{
				
				cout << "\a";
				cout << "Ничего не найденно" << endl;
			}
			else
			{
				cout << "Возможные переводы слова " << st1 << ":" << endl;
				for (i = dictionary.begin(); i != dictionary.end(); i++)
				{

					if (i->first == st1)
					{
						cout << i->second << endl;
					}
				}
			}
			break;



		case 2:
			cout << "Введите слово (на английском) >>";
			cin.get(); getline(cin, st1);
			cout << "Введите перевод (на русском) >>\n";
			getline(cin, st2);
			dictionary.insert(pair<string, string>(st1, st2));
			save(dictionary);
			break;



		case 3:
			cout << "Введите слово которое следует удалить (на английском) >>"; cin.get(); getline(cin, st1);
			res = dictionary.find(st1);
			if (res == dictionary.end())
			{
				cout << "\a";
				cout << "Ничего не найденно" << endl;
			}
			else
			{
				cout << "Вы точно хотите удалить слово -> " << st1 << endl;
				cout << "1::Да\n2::Нет\n>>"; cin >> menu;
				if (menu == 1)
				{
					for (i = dictionary.begin(); i != dictionary.end(); i++)
					{

						if (i->first == st1)
						{

							dictionary.erase(i);
							i = dictionary.begin();
						}
					}
				}
			}
			save(dictionary);
			break;

		case 4:
			cout << "Введите слово которое следует отредактировать (на английском) >>"; cin.get(); getline(cin, st1);
			res = dictionary.find(st1);
			if (res == dictionary.end())
			{
				for (int j = 0; j < 5; j++)
					cout << "\a";
				cout << "Ничего не найденно" << endl;
			}
			else
			{
				cout << "1::Изменить перевод (Русск)\n2::Удалить перевод (Русск)\n0::Отменить\n>>"; cin >> menu;
				for (i = dictionary.begin(); i != dictionary.end(); i++)
				{
					if (i->first == st1)
					{
						cout << "Вы хотите изменить/удалить этот перевод ->" << i->second << endl;
						cout << "1::Да\n2::Нет\n>>"; cin >> menu2;
						if (menu == 1 && menu2 == 1)
						{
							cout << "Введите перевод (на русском) >>\n";
							cin.get(); getline(cin, st2);
							i->second = st2;
							break;
						}
						else if (menu == 2 && menu2 == 1)
						{
							dictionary.erase(i);
							break;
						}
					}
				}
			}
			save(dictionary);
			break;


		default: cout << "\a";
			cout << "Ничего не найденно" << endl;
			break;
		}




		system("pause");



	} while (menu != 0);
	return 0;
}
