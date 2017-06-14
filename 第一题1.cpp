
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Telephone
{
 char name[20];
 char addrass[20];
 char zip[20];
 char telephone[20];
 struct Telephone *next;
};
typedef struct Telephone TEL;
TEL *head=NULL;
void showmenu();     
void Appenditem();     
void print();       
void Finditem1();    
void Removeitem();                     
void Saveandfree();      
void Open();     
void main()
{
 char ch;
 Open();   
 while(1)
 {
  showmenu(); 
  scanf(" %c",&ch);
  switch(ch)
  {
  case '1':Appenditem(); 
   break;
  case '2':print();
   break;
  case '3':Finditem1();  
   break;
  case '4': Removeitem();
   print();  
   break;
  case '0':Saveandfree(); 
   exit(0); 
   break;
  default:
   printf("ѡ�����");
   break;
  }
 }
}

void showmenu()
{
 printf("\n           ---------------ͨѶ¼ϵͳ------------------\n\n");
  printf("\                        1.���ͨѶ¼\n");
  printf("\                        2.ͨѶ¼���\n");
  printf("\                        3.�����ֲ�ѯ\n");
  printf("\                        4.ɾ����Ŀ\n");
  printf("\                        0.���沢�˳�!\n");
 printf("           -------------------------------------------\n\n");
 printf("\t��ѡ��:\n");
}

void Appenditem()
{
 TEL *p1=NULL,*p2=NULL;
 p1=(TEL *)malloc(sizeof(TEL));
 
 printf("��������:\n");         
 scanf("%s",p1->name);
 printf("�����ַ:\n");
 scanf("%s",p1->addrass);
 printf("��������:\n");
 scanf("%s",p1->zip);
 printf("����绰:\n");
 scanf("%s",p1->telephone);
 p1->next=NULL;           

 if(head==NULL)
 {
  head=(TEL *)malloc(sizeof(TEL));    
  head->next=p1;
 }
 else
 {
  for(p2=head;p2->next!=NULL;p2=p2->next);   
  p2->next=p1;
 }
 printf("����Ϣ�����!");
}

void print()
{
 TEL *p=NULL;
 if(head==NULL)
 {
  printf("ͨѶ¼�����޼�¼���������¼����ʹ�ñ�����!\n");
  return;
 }
 printf("---------------ͨѶ¼ϵͳ---------------\n");
  printf("����\t��ַ\t�ʱ�\t�绰\n");
 for(p=head->next;p!=NULL;p=p->next)
  printf("%s\t%s\t%s\t%s\n",p->name,p->addrass,p->zip,p->telephone);  
}

void Finditem1()//����
{
 TEL *p;
 char findname[20];
 printf("������Ҫ���ҵ�����:\n");
 scanf("%s",findname);
 

 for(p=head->next;p!=NULL;p=p->next)
 {
if(strcmp(p->name,findname)!=0)

	  printf("û�в��ҵ�����\n");
	  
 
 printf("---------------ͨѶ¼ϵͳ---------------\n");
  printf("����\t��ַ\t�ʱ�\t�绰\n");
  if(strcmp(p->name,findname)==0)
  printf("%s\t%s\t%s\t%s\n",p->name,p->addrass,p->zip,p->telephone);  
 }
}

void Removeitem()
{
 char findname[20];                 
 TEL *p = head->next, *pr = head->next;
 printf("������Ҫɾ��������:\n");
 scanf(" %s",&findname);
  if (head->next == NULL)    
  {
   printf("�޴˽ڵ�!\n");
   return;
  }
  while ((strcmp(p->name,findname)!=0 )&& p->next != NULL)
   {
    pr =p;
    p =p->next;
   }
  if (strcmp(findname, p->name)==0) 
   {
     printf("%s\t%s\t%s\t%s\n",p->next->name,p->next->addrass,\
      p->next->zip,p->next->telephone);  
    if (p == head->next)       
     head->next = p->next;  
    else 
     pr->next = p->next;   
   free(p);       
  }  
 printf("����Ϣ��ɾ��!");  
}

void Saveandfree()
{
 TEL *p=NULL;
 FILE *fp;
 char *Book="books.txt";
 if(head==NULL)
 {
  printf("\n��¼Ϊ��!\n");
  return;
 }
 else
  p=head->next;
  if((fp=fopen(Book,"wb+"))==NULL)
   {
    printf("\n�򲻿��ļ�!\n");
    return;
   }
  while(p!=NULL)
   {
    fwrite(p,sizeof(TEL),1,fp);
    p=p->next;
   }
  printf("�������!");
  fclose(fp);

  for(;head->next!=NULL;)
  {
   p=head->next;
   head->next=head->next->next;
   free(p);
  }
  free(head);
}

void Open()
{
 FILE *fp;
 TEL *p1=NULL,*p2=NULL,*temp=NULL;
 if((fp=fopen("books.txt","rb+"))==NULL)
  {
   printf("\n-------------------����һ���µ�ͨѶ¼����ϵͳ-------------------\n");
   return;
  }
 head=(TEL *)malloc(sizeof(TEL));
 head->next=NULL;
 temp=p2=head;
 while(! feof(fp)) 
  {
   p1=(TEL *)malloc(sizeof(TEL));
   temp=p2;
   p2->next=p1;
   p2=p1;
   fread(p1,sizeof(TEL),1,fp);
  }
 temp->next=NULL;
 fclose(fp);
}