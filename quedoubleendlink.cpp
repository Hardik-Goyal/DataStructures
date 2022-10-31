#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
using namespace std;

int q[MAX],front=0,rear=0;
void add_rear();
void add_front();
void delete_rear();
void delete_front();
void display();

 main()
{
int ch;

printf(" DQueue Menu");
printf("\n 1. Insert Rear");
printf("\n 2. Insert Front");
printf("\n 3. Delete Rear");
printf("\n 4. Delete Front");
printf("\n 5. Display");
printf("\n 6. Exit\n");
while(ch!=6)
{
printf(" Enter your choice:-");
scanf("%d",&ch);

switch(ch)
{
case 1:add_rear();
       break;

case 2:add_front();
       break;
case 3:delete_rear();
       break;
case 4:delete_front();
       break;
case 5:display();
       break;
case 6:exit(0);
       break;
default:printf(" Wrong Choice\n");
}
}
}

void add_rear()
{
                int no;
                  printf("\nEnter value to insert : ");
                  scanf("%d",&no);
                  if(rear==MAX)
                  {
                                   printf(" Queue is Overflow\n");
                                   return;
                  }
                  else
                  {
                                   rear++;
                                   q[rear]=no;
                                   if(rear==0)
                                                     rear=1;
                                    if(front==0)
                                                     front=1;
                  }
}
void add_front()
{
                  int no;
                  printf("\n Enter value to insert:-");
                  scanf("%d",&no);
                  if(front<=1)
                  {
                                   printf(" Cannot add value at front end\n");
                                   return;
                  }
                  else
                    {
                                front--;
                                q[front]=no;
                    }

                  }

void delete_front()
{
                  int no;
                  if(front==0)
                  {
                                   printf(" Queue is Underflow\n");
                                   return;
                  }
                  else
                  {
                                   no=q[front];
                                   printf("Deleted element is %d\n",no);
                                   if(front==rear)
                                   {
                                                     front=0;
                                                     rear=0;
                                   }
                                   else
                                   {
                                                     front++;
                                   }
                  }
}

void delete_rear()
{
                  int no;
                  if(rear==0)
                  {
                                   printf(" Cannot delete value at rear end\n");
                                   return;
                  }
                  else
                  {
                                   no=q[rear];
                                   if(front==rear)
                                   {
                                                     front=0;
                                                     rear=0;
                                   }
                                   else
                                   {
                                                     rear--;
                                                     printf(" Deleted element is %d\n",no);
                                   }
                  }
}

void display()
{
                  int i;
                  if(front==0)
                  {
                                   printf(" Queue is Underflow\n");
                                   return;
                  }
                  else
                  {
                                   printf("\n Output");
                                   for(i=front;i<=rear;i++)
                                   {
                                                     printf(" %d",q[i]);
                                   }
                  }
}
