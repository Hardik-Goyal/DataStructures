#include<iostream>
using namespace std;
struct queue
{
int capacity,front,rear;
int *Q,size=0;
};
void create(queue *q,int capacity)
{
    q->capacity=capacity;
    q->front=q->rear=-1;
    q->Q=new int[q->capacity];
}
void enqueue(queue *q,int x)
{
    if(q->rear==q->capacity-1)
    cout<<"queue is full"<<endl;
    else{
    q->rear++;
    q->Q[q->rear]=x;q->size++;}
}
void dequeue(queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    return;
     q->Q[q->front+1]=x;
    q->front++;
    q->size--;
}
void display(queue *q)
{
    if(q->front==q->rear)
    return;
    for(int i=q->front+1;i<=q->rear;i++)
    cout<<q->Q[i]<<" ";
    
}
int main()
{

    queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(&q);
    dequeue(&q);
    display(&q);
    
}