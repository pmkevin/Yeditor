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

void Quit(void)
{
 int i;
 char n,m;
 char buf1[30*14*2];
 gettext(25,10,54,13,buf1);
 window(25,10,54,13);
 textbackground(15);
 textcolor(0);
 putch(0xda);
 for(i=26;i<=53;i++)
 putch(0xc4);
 putch(0xbf);
 putch(0xb3);
 for(i=2;i<=29;i++)
  putch(32);
 putch(0xb3);
 putch(0xc0);
 for(i=26;i<=53;i++)
  putch(0xc4);
 putch(0xd9);
 gotoxy(5,2);
 cprintf("Really Quit? Y/N ");
 n=getchar();
 m=getchar();
 if(n=='y'||n=='Y')
      exit(0);
  else if(n=='n'||n=='N')
      puttext(25,10,54,13,buf1);
 return;
}


