#pragma hdrstop
#pragma argsused
#include <windows.h>
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <File1.cpp>

using namespace std;


void OutputMenu() {
	cout << "\n" << endl;
	cout << "������� ��������:" << endl;
	cout << "1. �������� ����" << endl;
	cout << "2. ������� ������" << endl;
	cout << "3. ����� �������������" << endl;
	cout << "4. �������" << endl;
	cout << "�������� ����� ��������:" << endl;

};

int main ()
{   SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_CTYPE,"Russian");

	int n;                              //���������� ���������
	int s;                          //�������
	char* x = new char[10];        //��� ��������������

	while (1) {
		OutputMenu();
		int k;
		cin >> k;

		switch (k) {

		case 1:
		   cout << "������� ���������� ���������  ";
		   cin >> n;                           //������ ���������� ���������

		    for (int i = 0; i < n; ++i)
	   {
        cout << "������� ������� ";
        cin >> s;
        cout << "������� ��� �������������� " << endl;
        cin >> x;                    //��������� ������� �� ���������
        push(s, x, &tree);                 //� ������ ������ � ������
		}

		  break;

		case 2:
			cout << "���� ������\n";
			print(tree, 0);
			break;
		case 3:
             cout << "������� ��� �������� ��������������" << endl;
			 cin >> x;
			 search(tree, x);
			break;

		case 4:
			goto m1;

		default:
			goto m1;
		}


	}

m1: cout << "Done!";
	return 0;
}
