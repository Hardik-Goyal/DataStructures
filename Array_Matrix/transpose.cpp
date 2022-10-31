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
    cout<<"Transpose"<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<a[j][i]<<" ";
        cout<<endl;
    }
}


