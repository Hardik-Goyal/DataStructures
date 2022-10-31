#include<iostream>
using namespace std;
struct dequeue
{
    int capacity,front,rear;
    int *Q,size=0;
};
void create(dequeue *q,int capacity)
{
    q->capacity=capacity;
    q->front=-1;
    q->rear=0;
    q->Q=new int[q->capacity];
}
bool isfull(dequeue *q){
    return((q->front==0&& q->rear==q->capacity-1)||q->front==q->rear+1);
}
bool isempty(dequeue *q)
{
    return q->front==-1;
}
void insertfront(dequeue *q,int x)
{
    if(isfull(q))
    return;
    if(q->front==-1){
q->front=q->rear=0;
    }
    else if(q->front==0)
    q->front=q->capacity-1;
    else
    {
        q->front--;
    }
    q->Q[q->front]=x;
    q->size++;

}
void insertrear(dequeue *q,int x)
{
    if(isfull(q))
    return;
    if(q->front==-1){
q->front=q->rear=0;
    }
    else if(q->rear==q->capacity-1)
    q->rear=0;
    else
    {
        q->rear++;
    }
    q->Q[q->rear]=x;
    q->size++;
   

}
void deletefront(dequeue *q)
{
    if(isempty(q))
    return;

    if(q->front==q->rear){
q->front=q->rear=-1;
    }
    else if(q->front==q->capacity-1)
    q->front=0;

    else
    {
        q->front++;
    }
    q->size--;
    

}
void deleterear(dequeue *q)
{
    if(isempty(q))
    return;
  
    if(q->front==q->rear){
q->front=q->rear=-1;
    }
    else if(q->rear==0)
    q->rear=q->capacity-1;
    else
    {
        q->rear--;
    }
    q->size--;

}
void display(dequeue *q)
{
    if(q->front==q->rear&&q->front!=0)
    return;
     int i=q->front;
    do
    {cout<<q->Q[i]<<" ";
        i=(i+1)%q->capacity;
    } while (i!=(q->rear+1)%q->capacity);
    cout<<endl;
}

int main()
{
    dequeue q;
    create(&q,6);
    insertfront(&q,10);
    display(&q);
    insertfront(&q,20);
     display(&q);
    insertrear(&q,30);
     display(&q);
    insertfront(&q,40);
     display(&q);
    insertfront(&q,50);
    deleterear(&q);
    
   display(&q);
   

}