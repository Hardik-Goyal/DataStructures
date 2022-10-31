#include<iostream>
using namespace std;
#define N 5
int queue[N];
int fro=-1, rear=-1;
void enqueue(int x)
{
    if(fro==-1&&rear==-1)
    {
        fro=0;
        rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==fro)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        rear =(rear+1)%N;
        queue[rear]=x;
    }
}
void deq()
{
    if(fro==-1&&rear==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(fro==rear)
    {
        cout<<queue[fro]<<endl;
        fro=-1;
        rear=-1;
    }
    else
    {
        cout<<queue[fro];
        fro=(fro+1)%N;
    }
}
void display()
{
    int i=fro;
    if(fro==-1&&rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    while(i!=rear)
    {
        cout<<queue[i]<<" "<<i<<endl;
        i=(i+1)%N;
    }
    cout<<queue[rear]<<" "<<rear<<endl;
}
int main()
{
   int option;
   while(1)
   {
        cout<<"Choose the option\n";
        cout<<"1.enqueue\n2.dequeue\n3.display\n4.exit\n";
        cin>>option;
       if(option==1)
       {
           int n;
           cout<<"Enter a number you want to enqueue\n";
           cin>>n;
           enqueue(n);

       }
       else if(option==2)
       {
           deq();

       }
       else if(option==3)
       {
           display();

       }
       else if(option==4)
       {
           exit;
       }
   }
   return 0;
}
