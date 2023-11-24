 #define _CRT_SECURE_NO_WARNINGS

//Листинг #1
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
//Наша структура
struct node
{
    int attr;
    char* id;                        //Информационное поле
    node* l, * r;                        //Левая и Правая часть дерева
};
node* tree = NULL;                      //Объявляем переменную, тип которой структура Дерево
/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(int a, char* b, node** t)
{
    if ((*t) == NULL)                   //Если дерева не существует
    {
        (*t) = new node;                //Выделяем память
        (*t)->attr = a;
        (*t)->id = new char[sizeof(b)];
        strcpy((*t)->id, b);                            //
       // *(*t)->id = *b;              //Кладем в выделенное место аргумент b
        (*t)->l = (*t)->r = NULL;       //Очищаем память для следующего роста
        return;                         //Заложили семечко, выходим
    }
    //Дерево есть
    if (strlen(b) > strlen((*t)->id)) push(a, b, &(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
    else push(a, b, &(*t)->l);         //Иначе кладем его влево
}
/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print(node* t, int u)
{
    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        for (int i = 0; i < u; ++i) cout << "|";
        cout << t->attr << " " << t->id << endl;      //И показываем элемент
        u--;
    }
    print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
}
void search(node* t, char* b)
{
    if (t == NULL)    return;    //Если дерева нет, выходим
    search(t->l, b); //Обошли левое поддерево
    search(t->r, b); //Обошли правое поддерево
    if (strcmp(t->id,b) == 0)
        cout << "Имя идентификатора: " << t->id << "\n Aтрибут: " << t->attr << endl;  //Посетили узел
}
