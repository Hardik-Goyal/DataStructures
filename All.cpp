
//Circular Queue
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


//DequeueDLL
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
