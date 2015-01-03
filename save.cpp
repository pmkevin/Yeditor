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

void Save(void)
{FILE *fp;
 int i;
 char t;
 char *p="Can't Create File";
 Node *strpTemp;
 t=25;
 if((fp=fopen(name,"w"))==NULL)
 textform(p);
 strpTemp=strpFirst;
 if(strpTemp==NULL)
 {fclose(fp);
  textform(p);
  return;}
 while(strpTemp!=strpRear)
 {if(strpTemp->nData!=13)
   fputc(strpTemp->nData,fp);
  else
   fputc(t,fp);
  strpTemp=strpTemp->strpNext;}
 if(strpTemp->nData!=13)
   fputc(strpTemp->nData,fp);
  else
   fputc(t,fp);
 fclose(fp);
 return;
}
