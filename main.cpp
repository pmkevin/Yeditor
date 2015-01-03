#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<bios.h>
#define Node struct node

void menu(void);
void New(void);
void Edit(void);
char *filename(void);
int IsEmpty_f(void);
int IsEmpty_et(void);
void InitialDoublelink_f(void);
void InitialDoublelink_et(void);
void Insert(char nValue);
void InsertEt(int nValue);
void scruproll(int n,int Edleft,int Edtop,int Edright,int Edbottom);
void scrdownroll(int n,int Edleft,int Edtop,int Edright,int Edbottom);
void KeyBS(void);
void Save(void);
void Open(void);
void Quit(void);
void menu_file(void);
void box(int startx,int starty,int high,int width);
void textform(char *info);
void KeyLeft(void);
void KeyRight(void);
void About(void);

char *name;

Node
{char nData;
 Node *strpNext;
 Node *strpPre;
 };
Node *strpFirst=NULL;
Node *strpRear=NULL;
Node *strpNow=NULL;
Node *CreatNode(char nValue);
Node *etFirst=NULL;
Node *etRear=NULL;
Node *etNow=NULL;
Node *CreatNode_f(char nValue);
Node *CreatEtNode(int nValue);

 main()
{menu();
 New();
}