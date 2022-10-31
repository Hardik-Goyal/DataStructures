#include<iostream>
using namespace std;
int fro=-1, rear=-1;
#define N 5
int queue[N];
void frontenque(int a)
{
    if((fro==0&&rear==N-1)||(rear+1==fro))
    {
        cout<<"Overflow"<<endl;
    }
    else if(fro==-1&&rear==-1)
    {
        fro=0;
        rear=0;
        queue[fro]=a;
    }
    else if(fro==0)
    {
        fro=N-1;
        queue[fro]=a;
    }
    else
    {
       fro--;
       queue[fro]=a;
    }
}
void rearenque(int a)
{
    if((fro==0&&rear==N-1)||(rear+1==fro))
    {
        cout<<"Overflow"<<endl;
    }
    else if(fro==-1&&rear==-1)
    {
        fro=0;
        rear=0;
        queue[rear]=a;
    }

    else
    {
       rear=(rear+1)%N;
       queue[rear]=a;
    }
}

void frontdeque()
{
    if(fro ==-1&&rear==-1)
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
      cout<<queue[fro]<<endl;
      fro=(fro+1)%N;
    }
}

void reardeque()
{
    if(fro ==-1&&rear==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(fro==rear)
    {
      cout<<queue[rear]<<endl;
      fro=-1;
      rear=-1;
    }
    else if(rear==0)
    {

       cout<< queue[rear]<<endl;
       rear=N-1;
    }
    else
    {
        cout<<queue[rear]<<endl;
        rear--;
    }
}

void display()
{
    int i=fro;
    if(fro ==-1&&rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
      while(i!=rear)
      {
          cout<<queue[i]<<" "<<i<<endl;
          i=(i+1)%N;
      }
      cout<<queue[rear]<<" "<<rear<<endl;
    }
}
int main()
{
    int option;
    while(1)
    {
         cout<<"Choose the option\n";
        cout<<"1.frontenque\n2.rearenque\n3.frontdeque\n4.reardeque\n5.display\n6.exit\n";
        cin>>option;
       if(option==1)
       {
           int n;
           cout<<"Enter a number you want to enque\n";
           cin>>n;
           frontenque(n);

       }
       if(option==2)
       {
           int n;
           cout<<"Enter a number you want to enque\n";
           cin>>n;
           rearenque(n);

       }
       else if(option==3)
       {
           frontdeque();

       }
       else if(option==4)
       {
          reardeque();

       }
       else if(option==5)
       {
           display();
       }
       else if(option==6)
       {
           exit(0);
       }
    }
    return 0;
}

