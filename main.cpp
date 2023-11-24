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
	cout << "Выбрать действие:" << endl;
	cout << "1. Добавить узлы" << endl;
	cout << "2. Вывести дерево" << endl;
	cout << "3. Найти идентификатор" << endl;
	cout << "4. Закрыть" << endl;
	cout << "Выберите номер действия:" << endl;

};

int main ()
{   SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_CTYPE,"Russian");

	int n;                              //Количество элементов
	int s;                          //атрибут
	char* x = new char[10];        //имя идентификатора

	while (1) {
		OutputMenu();
		int k;
		cin >> k;

		switch (k) {

		case 1:
		   cout << "Введите количество элементов  ";
		   cin >> n;                           //Вводим количество элементов

		    for (int i = 0; i < n; ++i)
	   {
        cout << "Введите атрибут ";
        cin >> s;
        cout << "Введите имя идентификатора " << endl;
        cin >> x;                    //Считываем элемент за элементом
        push(s, x, &tree);                 //И каждый кладем в дерево
		}

		  break;

		case 2:
			cout << "Ваше дерево\n";
			print(tree, 0);
			break;
		case 3:
             cout << "Введите имя искомого идентификатора" << endl;
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
