#include<iostream>
using namespace std;
struct deque{
    int cap;
    int front;
    int rear;
    int *p;
};
deque *ptr=new deque;
void create(void)
{
    ptr->front=-1;
    ptr->rear=-1;
    cout<<"Enter capacity of deque "<<endl;
    cin>>(ptr->cap);
    ptr->p =(int*) malloc(ptr->cap*sizeof(int)); 
}
bool isempty(void)
{
    if(ptr->front==-1)
    return true;
    return false;
}
bool isfull(void)
{
    if((ptr->rear+1)%ptr->cap==ptr->front)
    return true;
    return false;
}
void insert_at_end(void)
{
    int val;
    cout<<"Enter a value to insert "<<endl;
    cin>>val;
    if(isfull())
    cout<<"The deque is full can't insert a new element \n";
    else if(ptr->front==-1)
    {
        ptr->rear=(ptr->rear+1)%ptr->cap;
        ptr->p[ptr->rear]=val;
        ptr->front=0;
    }
    else
    {
        ptr->rear=(ptr->rear+1)%ptr->cap;
        ptr->p[ptr->rear]=val;
    }
}
void delete_at_begin(void)
{
    if(isempty())
    cout<<"The deque is empty no elements to delete "<<endl;
    else
    {
        cout<<"The popped out element is "<<ptr->p[ptr->front]<<endl;
        if(ptr->front==ptr->rear)
        {
            ptr->rear=-1;
            ptr->front=-1;
        }
        else
        ptr->front=(ptr->front+1)%ptr->cap;
    }
}
void delete_at_end(void)
{
    if(isempty())
    cout<<"No elements to delete "<<endl;
    else if(ptr->front==ptr->rear)
    {
        cout<<"The popped out element is "<<ptr->p[ptr->rear]<<endl;
        ptr->front=-1;
        ptr->rear=-1;
    }
    else
    {
        cout<<"The popped out element is "<<ptr->p[ptr->rear]<<endl;
        ptr->rear=(ptr->cap+ptr->rear-1)%ptr->cap;
    }
}
void insert_at_begin (void)
{
    int val;
    cout<<"Enter a value to insert "<<endl;
    cin>>val;
    if(isfull())
    cout<<"No can't insert as it is full "<<endl;
    else if(ptr->front==-1)
    {
        ptr->front=0;
        ptr->p[ptr->front]=val;
        ptr->rear=0;
    }
    else 
    {
        ptr->front=(ptr->cap+ptr->front-1)%ptr->cap;
        ptr->p[ptr->front]=val;
    }
}
int length(void)
{
    int len ;
    if (ptr->front==-1)
    len = 0;
    else if((ptr->front==ptr->rear)&&(ptr->front!=0))
    len =ptr->cap;
    else
    len=((ptr->rear-ptr->front+ptr->cap+1)%ptr->cap);
    return len;
}
int main ()
{
    create();
    while(1){
    cout<<" To insert element at beginning press 1"<< endl;
    cout<<" To insert element at end press 2 "<< endl;
    cout<<" To delete element at beginning press 3 "<<endl;
    cout<<" To delete element at end press 4 "<<endl;
    cout<<" To check if deque is empty press 5 "<<endl;
    cout<<" To check if deque is full press 6 "<<endl;
    cout<<" To get the size of deque press 7 "<<endl;
    int x;
    cin>>x;
    switch (x){
        case 1:
        insert_at_begin();
        break;
        case 2:
        insert_at_end();
        break;
        case 3:
        delete_at_begin();
        break;
        case 4:
        delete_at_end();
        break;
        case 5:
        if(isempty())
        cout<<"The deque is empty "<<endl;
        else
        cout<<"The deque is not empty "<<endl;
        break;
        case 6:
        if (isfull())
        cout<<"The deque is full "<<endl;
        else
        cout<<"The deque is not full "<<endl;
        break; 
        case 7:
        cout<<"The size of deque is "<<length()<<endl;
    }}
    return 0;
}