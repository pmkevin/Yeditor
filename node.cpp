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

int IsEmpty_f(void)
{if(strpFirst==NULL)
  return(0);
 else
  return(1);
}

int IsEmpty_et(void)
{if(etFirst==NULL)
  return(0);
 else
  return(1);
}

void InitialDoublelink_f(void)
{strpFirst=NULL;
 strpRear=NULL;
 strpNow=NULL;}

Node *CreatNode_f(char nValue)
{Node *strpNew;
 strpNew=(Node*)malloc(sizeof(Node));
 strpNew->nData=nValue;
 strpNew->strpNext=NULL;
 strpNew->strpPre=NULL;
 return(strpNew);
 }

Node *CreatEtNode(int nValue)
{Node *etNew;
 etNew=(Node*)malloc(sizeof(Node));
 etNew->nData=nValue;
 etNew->strpNext=NULL;
 etNew->strpPre=NULL;
 return(etNew);
 }

void Insert(char nValue)
{Node *strpNew,*strpTemp;
 char buf1[79*1*2];
 int x,y,t;
 strpNew=CreatNode_f(nValue);
 if(IsEmpty_f()==0)
 {strpFirst=strpRear=strpNow=strpNew;
  cprintf("%c",strpNow->nData);
  return;}
 else
  {if(strpNow==strpRear)
    {strpNow->strpNext=strpNew;
     strpNew->strpPre=strpNow;
     strpNow=strpNew;
     strpRear=strpNew;
     strpNew->strpNext=NULL;
     if(strpNew->nData!=13)
     cprintf("%c",strpNew->nData);
     else
     cprintf("\n%c",strpNew->nData);
     return;
     }
   else if(strpNow==NULL)
    {strpNew->strpNext=strpFirst;
     strpNow=strpNew;
     strpFirst->strpPre=strpNew;
     strpFirst=strpNow;
     strpTemp=strpNow;
     gotoxy(1,1);
     clrscr();
     if(strpTemp->nData!=13)
     {cprintf("%c",strpTemp->nData);
      strpTemp=strpTemp->strpNext;}
     else
     {cprintf("\n%c",strpTemp->nData);
      strpTemp=strpTemp->strpNext;}
     x=wherex();
     y=wherey();
     while((!(wherex()==79&&wherey()==24))&&strpTemp!=NULL)
     {if(strpTemp->nData!=13)
      {cprintf("%c",strpTemp->nData);
       strpTemp=strpTemp->strpNext;}
      else
      {if(wherey()==24)
       {gotoxy(x,y);
        return;}
       else
       {cprintf("\n%c",strpTemp->nData);
        strpTemp=strpTemp->strpNext;}
      }
     }
    if(strpTemp==NULL)
    gotoxy(x,y);
    if(wherex()==79&&wherey()==24&&strpTemp!=NULL)
    {if(strpTemp->nData==13)
     gotoxy(x,y);
     else
     {gettext(2,2,80,2,buf1);
      cprintf("%c",strpTemp->nData);
      scrdownroll(1,1,1,79,24);
      puttext(2,2,80,2,buf1);
      gotoxy(x,y);}
     }
    return;
   }
    else
     {strpTemp=strpNow->strpNext;
      strpNow->strpNext=strpNew;
      strpTemp->strpPre=strpNew;
      strpNew->strpNext=strpTemp;
      strpNew->strpPre=strpNow;
      strpNow=strpNew;
      strpTemp=strpNow;
      x=wherex();
      y=wherey();
      clreol();
      if(y!=24)
      {window(2,y+2,80,25);
       clrscr();
       window(2,2,80,25);}
      gotoxy(x,y);
      if(strpTemp->nData!=13)
      {cprintf("%c",strpTemp->nData);
       strpTemp=strpTemp->strpNext;}
      else
      {cprintf("\n%c",strpTemp->nData);
       strpTemp=strpTemp->strpNext;}
      x=wherex();
      y=wherey();
      while((!(wherex()==79&&wherey()==24))&&strpTemp!=NULL)
      {if(strpTemp->nData!=13)
        cprintf("%c",strpTemp->nData);
       else
        cprintf("\n%c",strpTemp->nData);
       strpTemp=strpTemp->strpNext;}
      if(strpTemp==NULL)
      {clreol();
       t=wherey();
       if(t!=24)
       {window(2,t+2,80,25);
        clrscr();
        window(2,2,80,25);}
        gotoxy(x,y);
       }
      if(wherex()==79&&wherey()==24)
       {gettext(2,2,80,2,buf1);
        if(strpTemp->nData!=13)
         cprintf("%c",strpTemp->nData);
        else
         cprintf("\n%c",strpTemp->nData);
        scrdownroll(1,1,1,79,24);
        puttext(2,2,80,2,buf1);
        gotoxy(x,y);}
      }
     return;
     }
   }



void InsertEt(int nValue)
{Node *etNew,*etTemp;
 etNew=CreatEtNode(nValue);
 if(IsEmpty_et()==0)
 {etFirst=etRear=etNow=etNew;
  return;}
 else
  {if(etNow==etRear)
    {etNow->strpNext=etNew;
     etNew->strpPre=etNow;
     etNow=etNew;
     etRear=etNew;
     etNew->strpNext=NULL;
     }
   else if(strpNow==NULL)
    {etNew->strpNext=etFirst;
     etNow=etNew;
     etFirst->strpPre=etNew;
     etFirst=etNow;
    }
    else
     {etTemp=etNow->strpNext;
      etNow->strpNext=etNew;
      etNow->strpPre=NULL;
      etTemp->strpPre=etNew;
      etNew->strpNext=etTemp;
      etNew->strpPre=etNow;
      etFirst=etNow;
      etNow=etNew;
     }
   }

}



