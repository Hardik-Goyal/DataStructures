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
    cout<<"Enter the scalor t by which you want to multiply?"<<endl;
    int t;
    cin>>t;
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cout<<t*(a[i][j])<<" ";
        cout<<endl;
    }
}