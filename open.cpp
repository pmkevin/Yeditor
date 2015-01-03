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

void Open(void)
{int ch,x,y;
 FILE *fp;
 Node *strpNew,*strpTemp=strpFirst;
 char *name1=name;
 char buf1[30*14*2];
 x=wherex();
 y=wherey();
 gettext(25,10,54,13,buf1);
 name=filename();
 if((fp=fopen(name,"r"))==NULL)
 {textform("Can't Open File");
  name=name1;
  puttext(25,10,54,13,buf1);
  gotoxy(x,y);
  return;}
 else
{while(strpTemp!=strpRear&&strpTemp!=NULL)
  {strpTemp=strpTemp->strpNext;
  free(strpTemp->strpPre);}
 free(strpTemp);
 window(2,2,80,25);
 clrscr();
 InitialDoublelink_f();
 name=filename();
 window(2,2,80,25);
 textbackground(0);
 textcolor(15);
 clrscr();
 gotoxy(1,1);
 strpNew=CreatNode_f(fgetc(fp));
 strpFirst=strpRear=strpNow=strpNew;
 if(strpNew->nData!=25)
   cprintf("%c",strpNew->nData);
  else
   {InsertEt(wherex());
    cprintf("\n\r");}
 while((ch=fgetc(fp))!=EOF)
 {strpNew=CreatNode_f(ch);
  strpNow->strpNext=strpNew;
  strpNew->strpPre=strpNow;
  strpNow=strpNew;
  strpRear=strpNew;
  strpNew->strpNext=NULL;
  if(strpNew->nData!=25)
   cprintf("%c",strpNew->nData);
  else
   {InsertEt(wherex());
    cprintf("\n\r");}
  }
 fclose(fp);
 return;}
}
