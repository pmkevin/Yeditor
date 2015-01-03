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

void scrdownroll(int n,int Edleft,int Edtop,int Edright,int Edbottom)
{union REGS reg;
 reg.h.ah=0x07;
 reg.h.al=n;
 reg.h.bh=1;
 reg.h.ch=Edtop;
 reg.h.cl=Edleft;
 reg.h.dh=Edbottom;
 reg.h.dl=Edright;
 int86(0x10,&reg,&reg);
 }

void scruproll(int n,int Edleft,int Edtop,int Edright,int Edbottom)
{union REGS reg;
 reg.h.ah=0x06;
 reg.h.al=n;
 reg.h.bh=1;
 reg.h.ch=Edtop;
 reg.h.cl=Edleft;
 reg.h.dh=Edbottom;
 reg.h.dl=Edright;
 int86(0x10,&reg,&reg);
}