#include<iostream>
using namespace std;
#define N 5
int deque[5];
int f=-1;
int r=-1;
void enqueuefront(int x)
{
    if((f==0&&r==N-1)||(f-1)==r)
    {
        cout<<"Overflow"<<endl;
    }
    else if(f==-1&&r==-1)
    {
        f=0, r=0;
        deque[f]=x;
    }
    else if(f==0)
    {
        f=N-1;
        deque[f]=x;
    }
    else
    {
        f--;
        deque[f]=x;
    }
}

void enqueuerear(int x)
{
   if((f==0&&r==N-1)||(r+1==f))
   {
    cout<<"Overflow"<<endl;
   }
  else if(f==-1&&r==-1)
   {
       f=0, r=0;
       deque[r]=x;
   }
   else if(r==N-1)
   {
       r=0;
       deque[r]=x;
   }
   else
   {
       r++;
       deque[r]=x;
   }
}

void display()
{
    int i=f;
    if(r==-1&&f==-1)
    {
        cout<<"Underflow"<<endl;
    }
    while(i!=r)
    {
        cout<<deque[i]<<endl;
        i=(i+1)%N;
    }

    cout<<deque[r]<<endl;
}

void dequefront()
{
    if(f==-1&&r==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(f==r)
    {
        cout<<deque[f]<<endl;
        f=-1, r=-1;
    }
    else if(f==N-1)
    {
        cout<<deque[f]<<endl;
        f=0;
    }
    else
    {
        cout<<deque[f]<<endl;
        f++;
    }
}

void dequerear()
{
    if(r==-1&&f==-1)
    {
        cout<<"Underflow"<<endl;

    }
    else if(f==r)
    {
        cout<<deque[r]<<endl;
        f=-1, r=-1;
    }
    else if(r==0)
    {
        cout<<deque[r]<<endl;
        r=N-1;
    }
    else
    {
        cout<<deque[r]<<endl;
        r--;
    }

}

int main()
{
    while(1)
    {
        int c;
        cout<<endl;
        cout<<"Enter a Choice\n";
        cout<<"1.Enqueuefront\n2.Enqueuerear\n3.Dequeuefront\n4.Dequerear\n5.Display\n6.Exit"<<endl;
        cin>>c;
        if(c==1)
        {
            int n;
            cout<<"Enter a number you want to insert"<<endl;
            cin>>n;
            enqueuefront(n);
        }
        else if(c==2)
        {
            int n;
            cout<<"Enter a number you want to insert"<<endl;
            cin>>n;
            enqueuerear(n);
        }
        else if(c==3)
        {
            dequefront();
        }
        else if(c==4)
        {
            dequerear();
        }
        else if(c==5)
        {
            display();
        }
        else if(c==6)
        {
          exit(0);
        }

    }
    return 0;
}




