#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
struct dequeue
{
    int size=0;
    node *front,*rear;


};
void create(dequeue *q)
{
    q->front=q->rear=NULL;
}
void insertfront(dequeue *q,int dat)
{
    node *new_node=new node;
    new_node->data=dat;
    new_node->prev=NULL;
    if(q->front==NULL)
    {   new_node->next=NULL;
        q->front=new_node;q->rear=new_node;
        q->size++;
    }else{
    new_node->next=q->front;q->front->prev=new_node;
    q->front=new_node;q->size++;}
}

void insertrear(dequeue *q,int dat)
{
    node *new_node=new node;
    new_node->data=dat;
     new_node->next=NULL;
    if(q->front==NULL)
    {   new_node->prev=NULL;
        q->front=new_node;q->rear=new_node;
        q->size++;
    }else{
    new_node->prev=q->rear;
    q->rear->next=new_node;
    q->rear=new_node;q->size++;}
}
void deletefront(dequeue *q)
{
    node *temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        
        q->rear=NULL;
        delete temp;
        return;
    }
    q->front->prev=NULL;
    
    delete temp;

}
void deleterear(dequeue *q)
{
    node *temp=q->rear;
    q->rear=q->rear->prev;
    if(q->rear==NULL)
    {   
        q->front=NULL;
      
        delete temp;
        return;
    }
    q->rear->next=NULL;
   
    
    
    delete temp;

}
void dis(dequeue *q)
{
    if(q->front==NULL)
    cout<<"QUEUE IS EMPTY"<<endl;
    else {node *n=q->front;
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
    }
}
int main()
{
    dequeue q;
    create(&q);
    insertfront(&q,10);
    dis(&q);
    insertfront(&q,20);
     dis(&q);
    insertrear(&q,30);
     dis(&q);
    insertfront(&q,40);
     dis(&q);
    insertfront(&q,50);
    deleterear(&q);
    
   dis(&q);

}