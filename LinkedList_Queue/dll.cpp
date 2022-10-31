#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
void push(node **head,int dat)
{
    node *new_node=new node;
    new_node->data=dat;
    new_node->prev=NULL;
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
    node *prev_node=*head;
    if(pos==0){
    *head=prev_node->next;
    delete prev_node;return;}
      for (int i=0; prev_node!=NULL && i<pos-1; i++) 
         prev_node = prev_node->next; 

        if(prev_node==NULL || prev_node->next==NULL)
        return;
        node *n=prev_node->next->next;
        n->prev=prev_node;
        delete prev_node->next;
        prev_node->next=n;
}
void append(node **head,int dat)
{
    node *new_node=new node;
    new_node->data=dat;
    new_node->next=NULL;
    node *last=*head;
    if(*head==NULL){new_node->prev=NULL;
    ;*head=new_node;}
    else{
        while(last->next!=NULL)
        last=last->next;
        last->next=new_node;
        new_node->prev=last;
    }
}
void insert(node **head,int dat,int pos)
{
    node *new_node=new node;
    new_node->data=dat;
    if(pos==0){new_node->prev=NULL;
    new_node->next=NULL;*head=new_node;}
    node *prev_node=*head;
    
    for(int i=0;i<pos;i++)
    prev_node=prev_node->next;
    
    new_node->next=prev_node->next;
    prev_node->next=new_node;
    new_node->prev=prev_node;
    if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
}
void display(node *n)
{  node *last;
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        last=n;
        n=n->next;
    }
    while(last!=NULL)
    {cout<<last->data<<" ";
    last=last->prev;}
    
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