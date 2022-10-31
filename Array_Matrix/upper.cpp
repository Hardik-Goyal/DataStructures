#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the order of 1st matrix (m,n)"<<endl;
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    cout<<"Upper triangular matrix"<<endl;
    
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            if(i<=j)
        cout<<(a[i][j])<<" ";
          else 
        {
            cout<<"0"<<" ";
        }}
        cout<<endl;
    }
       cout<<"lower triangular matrix"<<endl;
    
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            if(i>=j)
        cout<<(a[i][j])<<" ";
         else 
        {
            cout<<"0"<<" ";
        }
        }
        cout<<endl;
    }
}