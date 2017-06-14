
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
   printf("选择错误");
   break;
  }
 }
}

void showmenu()
{
 printf("\n           ---------------通讯录系统------------------\n\n");
  printf("\                        1.添加通讯录\n");
  printf("\                        2.通讯录输出\n");
  printf("\                        3.按名字查询\n");
  printf("\                        4.删除条目\n");
  printf("\                        0.保存并退出!\n");
 printf("           -------------------------------------------\n\n");
 printf("\t请选择:\n");
}

void Appenditem()
{
 TEL *p1=NULL,*p2=NULL;
 p1=(TEL *)malloc(sizeof(TEL));
 
 printf("输入姓名:\n");         
 scanf("%s",p1->name);
 printf("输入地址:\n");
 scanf("%s",p1->addrass);
 printf("输入邮箱:\n");
 scanf("%s",p1->zip);
 printf("输入电话:\n");
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
 printf("此信息已添加!");
}

void print()
{
 TEL *p=NULL;
 if(head==NULL)
 {
  printf("通讯录中暂无记录，请输入记录后再使用本功能!\n");
  return;
 }
 printf("---------------通讯录系统---------------\n");
  printf("姓名\t地址\t邮编\t电话\n");
 for(p=head->next;p!=NULL;p=p->next)
  printf("%s\t%s\t%s\t%s\n",p->name,p->addrass,p->zip,p->telephone);  
}

void Finditem1()//查找
{
 TEL *p;
 char findname[20];
 printf("请输入要查找的姓名:\n");
 scanf("%s",findname);
 

 for(p=head->next;p!=NULL;p=p->next)
 {
if(strcmp(p->name,findname)!=0)

	  printf("没有查找的姓名\n");
	  
 
 printf("---------------通讯录系统---------------\n");
  printf("姓名\t地址\t邮编\t电话\n");
  if(strcmp(p->name,findname)==0)
  printf("%s\t%s\t%s\t%s\n",p->name,p->addrass,p->zip,p->telephone);  
 }
}

void Removeitem()
{
 char findname[20];                 
 TEL *p = head->next, *pr = head->next;
 printf("请输入要删除的姓名:\n");
 scanf(" %s",&findname);
  if (head->next == NULL)    
  {
   printf("无此节点!\n");
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
 printf("此信息已删除!");  
}

void Saveandfree()
{
 TEL *p=NULL;
 FILE *fp;
 char *Book="books.txt";
 if(head==NULL)
 {
  printf("\n记录为空!\n");
  return;
 }
 else
  p=head->next;
  if((fp=fopen(Book,"wb+"))==NULL)
   {
    printf("\n打不开文件!\n");
    return;
   }
  while(p!=NULL)
   {
    fwrite(p,sizeof(TEL),1,fp);
    p=p->next;
   }
  printf("保存完毕!");
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
   printf("\n-------------------这是一个新的通讯录管理系统-------------------\n");
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