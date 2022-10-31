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
    q->front=q->rear=0;
    q->Q=new int[q->capacity];
}
void enqueue(queue *q,int x)
{
    if((q->rear+1)%q->capacity==q->front)
    cout<<"queue is full"<<endl;
    else{
    q->rear=(q->rear+1)%q->capacity;
    q->Q[q->rear]=x;q->size++;}
}
void dequeue(queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    return;
     q->front=(q->front+1)%q->size;
     q->Q[q->front]=x;
    q->size--;
}
void display(queue *q)
{
    if(q->front==q->rear)
    return;
     int i=q->front+1;
    do
    {cout<<q->Q[i]<<" ";
        i=(i+1)%q->capacity;
    } while (i!=(q->rear+1)%q->capacity);
    cout<<endl;
}
int main()
{

    queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q,50);
    display(&q);
    
}