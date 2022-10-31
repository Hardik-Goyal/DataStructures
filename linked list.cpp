#include<bits/stdc++.h>
using namespace std;
void display(struct node*);
struct node
{
    int data;
    struct node *next;
};
void create(int *a, int n)
{
   struct node* head, *newnode, *temp;
   head=0;
   for(int i=0;i<n;i++){
   newnode=new node;
   newnode->data=a[i];
   if(head==0)
   {
       head=newnode;
       temp=newnode;
   }
   else
   {
       temp->next=newnode;
       temp=newnode;
   }
   }
   temp=head;
   display(temp);
}
void display(struct node *temp)
{
  while(temp!=0)
  {
      cout<<temp->data<<" ";
      temp=temp->next;
  }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    create(a, n);
   return 0;
}
