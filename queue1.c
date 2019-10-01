#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node * NODE;
NODE getnode();
NODE push(NODE head,int item);
NODE pop(NODE head);
void display(NODE head);
int main()
{
NODE head=NULL;
int ch,item;
do
{
printf("press\n1:push\n2:pop\n3:display\n4:exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("enter the element you want to insert");
scanf("%d",&item);
head=push(head,item);
break;
case 2:head=pop(head);
       break;
case 3:display(head);
       break;
case 4:break;
default:printf("invalid choice\n");
        break;
};
}while(ch!=4);
return 0;
}
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("memory could not be allocated\n");
exit(0);
}
}
NODE push(NODE head,int item)
{
NODE p;
p=getnode();
p->data=item;
p->next=head;
head=p;
return head;
}
NODE pop(NODE head)
{
NODE p=head;
if(head==NULL)
{
printf("list is empty\n");
return head;
}
printf("deleted element is %d\n",p->data);
head=p->next;
free(p);
return head;
}
void display(NODE head)
{
NODE p;
if(head==NULL)
{
printf("list is empty\n");
exit(0);
}
p=head;
while(p!=NULL)
{
printf("%d",p->data);
printf("\n");
p=p->next;
}
}
