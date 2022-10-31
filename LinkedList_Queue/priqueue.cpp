#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head;
node* create(void)
{
    node*p=new node;
    return p;
}
void display(void)
{
    node *t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
void push (int val)
{
    node*p=create();
    p->data=val;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else if(head->data>val)
    {
        p->next=head;
        head=p;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL&&temp->next->data<val)
        temp=temp->next;
        p->next=temp->next;
        temp->next=p;
    }
}
void pop(void)
{
    if(head==NULL)
    {
        cout<<"No elements to delete \n";
    }
    else
    {
        cout<<"The popped out element is "<<head->data<<endl;
        node*temp=head;
        head=head->next;
        delete temp;
    }
}
void isempty()
{
    if(head==NULL)
    cout<<"The priority queue is empty"<<endl;
    else
    cout<<"The priority queue is not empty "<<endl;
}
int main ()
{
    while(1)
    {
        cout<<"To check if priority queue is empty press 1 \n";
        cout<<"To push a new element press 2 \n";
        cout<<"To pop a new element press 3 \n";
        cout<<"To display the whole priority queue press 4 \n";
        int x;
        cin>>x;
        switch (x)
        {
        case 1:
        isempty();
        break;
        case 2:
        cout<<"Enter a element to push \n";
        int y;
        cin>>y;
        push(y);
        break;
        case 3:
        pop();
        break;
        case 4:
        display();
        break;
        }
    }
    return 0;
}