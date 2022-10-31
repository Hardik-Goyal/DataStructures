#include<iostream>
using namespace std;
int fro=-1, rear=-1;
#define N 5
int queue[N];
void enque(int a)
{
    if(rear==N-1)
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
       rear++;
       queue[rear]=a;
    }
}

void deque()
{
    if(fro ==-1&&rear==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(fro==rear)
    {
      cout<<queue[rear];
      fro=-1;
      rear=-1;
    }
    else
    {
        cout<<queue[fro]<<endl;
        fro++;
    }
}
void display()
{
    if(fro ==-1&&rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        for(int i=fro;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int option;
    while(1)
    {
         cout<<"Choose the option\n";
        cout<<"1.enque\n2.deque\n3.display\n4.exit\n";
        cin>>option;
       if(option==1)
       {
           int n;
           cout<<"Enter a number you want to enque\n";
           cin>>n;
           enque(n);

       }
       else if(option==2)
       {
           deque();

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
