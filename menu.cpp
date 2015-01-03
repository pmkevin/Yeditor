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

void menu(void)
{int i,l,x,y;
 char *menu[]={"File","About","     ","    "};
 char *red[]={"F","A"," "," "};
 textmode(C80);
 window(1,1,80,1);
 textbackground(15);
 textcolor(BLACK);
 clrscr();
 for(i=0,l=0;i<4;i++)
 {x=wherex();
  y=wherey();
  cprintf("   %s",menu[i]);
  l=strlen(menu[i]);
  gotoxy(x,y);
  textcolor(RED);
  cprintf("   %s",red[i]);
  x=x+l+3;
  gotoxy(x,y);
  textcolor(BLACK);
 }
 textbackground(0);
 textcolor(15);
 window(1,2,1,25);
 for(i=2;i<=24;i++)
  putch(186);
 window(1,2,3,25);
 gotoxy(1,24);
 putch(186);
}
