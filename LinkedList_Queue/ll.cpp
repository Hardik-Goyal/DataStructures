#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void push(node **head,int dat)
{
    node *new_node=new node;
    new_node->data=dat;
    if(*head==NULL)
    new_node->next=NULL;
    else
    {
        new_node->next=(*head);
    }

    *head=new_node;
}
void Delete(node **head,int pos)
{
    if(*head==NULL)
    return;
    node *prev=*head;
    if(pos==0){
    *head=prev->next;
    delete prev;return;}
      for (int i=0; prev!=NULL && i<pos-1; i++)
         prev = prev->next;

        if(prev==NULL || prev->next==NULL)
        return;
        node *n=prev->next->next;
        delete prev->next;
        prev->next=n;
}
void append(node **head,int dat)
{
    node *new_node=new node;
    new_node->data=dat;
    new_node->next=NULL;
    node *last=*head;
    if(*head==NULL){
    ;*head=new_node;}
    else{
        while(last->next!=NULL)
        last=last->next;
        last->next=new_node;
    }
}
void insert(node **head,int dat,int pos)
{
    node *new_node=new node;
    new_node->data=dat;
    if(pos==0){
    new_node->next=NULL;*head=new_node;}

    node *prev_node=*head;

    for(int i=0;i<pos;i++)
    prev_node=prev_node->next;
    new_node=prev_node->next;
    prev_node->next=new_node;
}
void display(node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
 int main()
 {
   node *head=NULL;
   append(&head,13);
   push(&head,10);
   push(&head,11);
   push(&head,12);

   append(&head,14);
   insert(&head,15,3);
   Delete(&head,2);
   display(head);
 }
