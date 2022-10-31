#include<iostream>
using namespace std;
int c;
int insert(int *a,int n,int x,int p)
{   if(p<=n){
    if(n==c){
    cout<<"Array is full"<<endl;return n;}
    else
    {
        for(int i=n-1;i>p-1;i--)
        {
            a[i+1]=a[i];
        }
        a[p]=x;
        n++;
        return n;
    }


}}
int Delete(int *a,int n,int p)
{   if(p<n){
    if(n==0){
    cout<<"Array is empty"<<endl;return n;}
    else
    {
        for(int i=p;i<n-1;i++)
        {
            a[i]=a[i+1];
        }

        n--;
        return n;
    }


}}


void Display(int *a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}



int main()
{
    int n;
    cout<<"ENTER CAPACITY AND SIZE OF ARRAY"<<endl;
    cin>>c>>n;
    cout<<"enter elements"<<endl;
    int a[c];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Display(a,n);
    n=insert(a,n,10,3);
    Display(a,n);
    n=Delete(a,n,3);
    Display(a,n);

}
