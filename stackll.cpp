#include<iostream>
using namespace std;
struct node
{
  int data;
  node *link;
};
struct head
{
  int count;
  node *top;
}*slist;
void create()

{
  slist=new head();
  slist->count=0;
  slist->top=NULL;
 }
void push(int x)
{
  node *newnode=new node();
  if(newnode!=NULL)
  {
    newnode->data=x;
    newnode->link=slist->top;
    slist->top=newnode;
    (slist->count)++;
  }
}
int pop()
{
  if(slist->count!=0)
  {
		int data;
    node *temp=slist->top;
    slist->top=slist->top->link;
    data=temp->data;
    delete temp;
    (slist->count)--;
    return data;
  }
}
void disp()
{
  node *temp=slist->top;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->link;
  }
}
int main()
{
  char h;
  create();
  do
  {
  cout<<"\n1.push,2.pop,3.disp\n";
  cout<<"enter your choice: ";
  int ch=0;
  cin>>ch;
  int ele,data;
  switch(ch)
  {
     case 1:
      cout<<"\nenter element :";
      cin>>ele;
      push(ele);
      break;
      case 2:
        data=pop();
        cout<<"\n"<<data<<"poped\n";
        break;
      case 3:
        disp();
        break;
  } 
  cout<<"\ndo you want to continue :";
  cin>>h;
  }while(h=='y'||h=='Y');
  return 0;
}

