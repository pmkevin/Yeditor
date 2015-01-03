#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<bios.h>
#define Node struct node

Node
{char nData;
 Node *strpNext;
 Node *strpPre;
 };

extern char *name;
extern Node *strpFirst=NULL;
extern Node *strpRear=NULL;
extern Node *strpNow=NULL;
extern Node *CreatNode(char nValue);
extern Node *etFirst=NULL;
extern Node *etRear=NULL;
extern Node *etNow=NULL;
extern Node *CreatNode_f(char nValue);
extern Node *CreatEtNode(int nValue);

char *filename(void)
{
 char *p;
 int i;
 window(25,10,54,13);
 textbackground(15);
 textcolor(0);
 putch(0xda);
 cputs("Input file's name");
 for(i=0;i<=10;i++)
  putch(196);
 putch(0xbf);
 putch(179);
 for(i=2;i<=29;i++)
  putch(32);
 putch(179);
 putch(0xc0);
 for(i=26;i<=53;i++)
  putch(196);
 putch(0xd9);
 gotoxy(5,2);
 return(gets(p));
 }
