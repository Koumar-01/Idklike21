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
		cout << "\t�����-������� �������" << endl;
		cout << "1::����� �����" << endl;
		cout << "2::�������� ����� / �������� �������" << endl;
		cout << "3::������� �����" << endl;
		cout << "4::������������� ��������" << endl;
		cout << "0::Exit" << endl;
		cout << "=======================\n" << endl;
		cout << ">>";
		cin >> menu;



		switch (menu)
		{
		case 0: break;
		case 1:
			cout << "������� ����� (�� ����������) >>\n";
			cin.get(); getline(cin, st1);
			res = dictionary.find(st1);
			if (res == dictionary.end())
			{
				
				cout << "\a";
				cout << "������ �� ��������" << endl;
			}
			else
			{
				cout << "��������� �������� ����� " << st1 << ":" << endl;
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
			cout << "������� ����� (�� ����������) >>";
			cin.get(); getline(cin, st1);
			cout << "������� ������� (�� �������) >>\n";
			getline(cin, st2);
			dictionary.insert(pair<string, string>(st1, st2));
			save(dictionary);
			break;



		case 3:
			cout << "������� ����� ������� ������� ������� (�� ����������) >>"; cin.get(); getline(cin, st1);
			res = dictionary.find(st1);
			if (res == dictionary.end())
			{
				cout << "\a";
				cout << "������ �� ��������" << endl;
			}
			else
			{
				cout << "�� ����� ������ ������� ����� -> " << st1 << endl;
				cout << "1::��\n2::���\n>>"; cin >> menu;
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
			cout << "������� ����� ������� ������� ��������������� (�� ����������) >>"; cin.get(); getline(cin, st1);
			res = dictionary.find(st1);
			if (res == dictionary.end())
			{
				for (int j = 0; j < 5; j++)
					cout << "\a";
				cout << "������ �� ��������" << endl;
			}
			else
			{
				cout << "1::�������� ������� (�����)\n2::������� ������� (�����)\n0::��������\n>>"; cin >> menu;
				for (i = dictionary.begin(); i != dictionary.end(); i++)
				{
					if (i->first == st1)
					{
						cout << "�� ������ ��������/������� ���� ������� ->" << i->second << endl;
						cout << "1::��\n2::���\n>>"; cin >> menu2;
						if (menu == 1 && menu2 == 1)
						{
							cout << "������� ������� (�� �������) >>\n";
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
			cout << "������ �� ��������" << endl;
			break;
		}




		system("pause");



	} while (menu != 0);
	return 0;
}
