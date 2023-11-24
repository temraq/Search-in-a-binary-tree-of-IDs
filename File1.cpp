 #define _CRT_SECURE_NO_WARNINGS

//������� #1
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
//���� ���������
struct node
{
    int attr;
    char* id;                        //�������������� ����
    node* l, * r;                        //����� � ������ ����� ������
};
node* tree = NULL;                      //��������� ����������, ��� ������� ��������� ������
/*������� ������ �������� � �������� ������*/
void push(int a, char* b, node** t)
{
    if ((*t) == NULL)                   //���� ������ �� ����������
    {
        (*t) = new node;                //�������� ������
        (*t)->attr = a;
        (*t)->id = new char[sizeof(b)];
        strcpy((*t)->id, b);                            //
       // *(*t)->id = *b;              //������ � ���������� ����� �������� b
        (*t)->l = (*t)->r = NULL;       //������� ������ ��� ���������� �����
        return;                         //�������� �������, �������
    }
    //������ ����
    if (strlen(b) > strlen((*t)->id)) push(a, b, &(*t)->r); //���� �������� � ������ ��� ������� �������, ������ ��� ������
    else push(a, b, &(*t)->l);         //����� ������ ��� �����
}
/*������� ����������� ������ �� ������*/
void print(node* t, int u)
{
    if (t == NULL) return;                  //���� ������ ������, �� ���������� ������, �������
    else //�����
    {
        print(t->l, ++u);                   //� ������� ������������ �������� ����� ���������
        for (int i = 0; i < u; ++i) cout << "|";
        cout << t->attr << " " << t->id << endl;      //� ���������� �������
        u--;
    }
    print(t->r, ++u);                       //� ������� �������� �������� ������ ���������
}
void search(node* t, char* b)
{
    if (t == NULL)    return;    //���� ������ ���, �������
    search(t->l, b); //������ ����� ���������
    search(t->r, b); //������ ������ ���������
    if (strcmp(t->id,b) == 0)
        cout << "��� ��������������: " << t->id << "\n A������: " << t->attr << endl;  //�������� ����
}
