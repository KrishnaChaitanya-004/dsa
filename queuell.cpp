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
  node *r;
	node *f;
}*qlist;
void create()

{
  qlist=new head();
  qlist->count=0;
  qlist->r=NULL;
  qlist->f=NULL;
 }
void enqueue(int x)
{
  node *newnode=new node();
  if(newnode!=NULL)
  {
    newnode->data=x;
    newnode->link=NULL;
    if(qlist->f==NULL)
    {
    	qlist->r=newnode;
    	qlist->f=newnode;
    }
    else
    {
     qlist->r->link=newnode;
     qlist->r=newnode;
    }
    (qlist->count)++;
  }
}
int dequeue()
{
  if(qlist->count!=0)
  {
		int data;
		node *temp;
		if(qlist->f==NULL)
			cout<<"queue empty";
		else
		{
    temp=qlist->f;
    data=temp->data;
    }
    if(qlist->count==1)
    {
      qlist->r=NULL;
    	qlist->f=NULL;
    }
    else
    {
    qlist->f=qlist->f->link;
    }
    data=temp->data;
    delete temp;
    (qlist->count)--;
    return data;
  }
  return-1;
}
void disp()
{
	if(qlist->count==0)
		cout<<"queueis empty";
	else
	{
		node *temp=qlist->f;
		while(temp!=NULL)
		{
		  cout<<temp->data<<" ";
		  temp=temp->link;
		}
	}
}
int main()
{
  char h;
  int ele,data;
  create();
  do
  {
  cout<<"\n1.push,2.pop,3.disp\n";
  cout<<"enter your choice: ";
  int ch=0;
  cin>>ch;
  switch(ch)
  {
     case 1:
      cout<<"\nenter element :";
      cin>>ele;
      enqueue(ele);
      break;
      case 2:
        data=dequeue();
        if(data==-1)
        	cout<<"queue is empty";
        else
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

