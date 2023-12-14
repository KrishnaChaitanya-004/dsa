#include<iostream>
using namespace std;
struct node
{
	int data;
	node* fore;
	node* back;
};
struct list 
{
	int count;
	node* head;
  node* rear;
};
class dll
{
	list *headnode;
	node *predecessor,*sucessor;
public:
	dll()
	{
		headnode=NULL;
	}
//creating
	void create()
	{
		headnode=new list();
		headnode->count=0;
		headnode->head=NULL;
		headnode->rear=NULL;
		cout<<"done\n";
	}
//is dll full??
	bool fulldll()
	{
		node *temp=new node;
		if(temp==new node)
		{
			delete temp;
			return false;
		}
		return true;
	}
//is dll empty??
	bool emptydll()
	{
		if(headnode->count==0)
		return true;
		return false;
	}
//searching
	bool search(int ele)
	{
		predecessor=NULL;
		sucessor=headnode->head;
		while(sucessor!=NULL&&ele>sucessor->data)
		{
			predecessor=sucessor;
			sucessor=sucessor->fore;
		}
		if(sucessor==NULL)
		return false;
		if(ele==sucessor->data)
		return true;
		return false;
	}
//inserting
	int insert(int ele)
	{
		if(!fulldll())
		return 0;
		sucessor=NULL;
		predecessor=NULL;
		int found=search(ele);
		if(!found)
		{
			cout<<"done\n";	
			node *newnode=new node;
			newnode->data=ele;
			headnode->count++;
			if(predecessor==NULL)
			{
				newnode->back=NULL;
				newnode->fore=headnode->head;
				headnode->head=newnode;
			}
			else
			{
				newnode->back=predecessor;
				newnode->fore=sucessor;
				predecessor->fore=newnode;
			}
			if(sucessor==NULL)
				headnode->rear=newnode;
			else
				sucessor->back=newnode;
			  return 1;
		}
		return 2;
	}
//deleting
	bool del(int del)
	{
		node *delnode;
		sucessor=NULL;
		predecessor=NULL;
		int found=search(del);
		if(!found)
			return false;
			delnode=sucessor;
	if(delnode->back!=NULL)
		{
			predecessor=delnode->back;
			predecessor->fore=delnode->fore;
			cout<<"\nelement deleted: "<<delnode->data;
			predecessor->fore=delnode->fore;
		}
		else
		{
			headnode->head=delnode->fore;
		}
		if(delnode->fore!=NULL)
		{
			sucessor=delnode->fore;
			sucessor->back=delnode->back;
		}
		else 
			{
			headnode->rear=delnode->back;
			}
			(headnode->count)--;
			delete delnode;
			return true;
	}
//do you want display from front?
	void display1()
	{
		cout<<"\nlist elements";
		node*temp=headnode->head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->fore;
		}
		cout<<endl;
	}
//do you want display from rear?
	void display2()
	{
		cout<<"\nlist elements";
		node*temp=headnode->rear;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->back;
		}
		cout<<endl;
	}
//what is countof dll?
	int returncount()
	{
		return headnode->count;
	}	
//do you want position of element from front?	
	int search1(int y)
	{
		int x=0;
		node*temp=headnode->head;
		while(temp!=NULL)
		{ 
			x++;
			if(temp->data==y);
				return x;
			temp=temp->fore;
		}
		return -1;
	}
//do you want position of element from rear?
	int search2(int y)
	{
		int x=headnode->count;
		node*temp=headnode->rear;
		while(temp!=NULL)
		{
			x--;
			if(temp->data==y);
			return x;
			temp=temp->back;
		}
		return -1;
   }
};
int main()
{
 dll s;
 int ch,x;
 bool success;
 int success2;
 s.create();
cout<<"=>1)inserting\n=>2)deleting\n=>3)searching\n=>4)is dll full??\n=>5)is dll empty??\n=>6)what is countof dll?\n=>7)do you want display from front?\n=>8)do you want display from rear?\n=>9)do you want position of element from front?\n=>10)do you want position of element from rear?\n=>0)do you want to exit?!!!(* ^ *)\n";
   cout <<"enter ur choice: ";
 do
 {
  cin>>ch;
  switch(ch)
  {
//inserting
		case 1:
			cout<<"\nenter element to insert: ";
			cin>>x;
			success2=s.insert(x);
			if(success2==0)
				cout<<"\nmight be memory full";
			else if(success2==2)
			 	cout<<"\n might be duplication attempt!";
			else  if(success2==1)
				 cout<<"\n element inserted succesfully";
			break;
//deleting
		 case 2:
			 cout<<"\nenter element to delete: ";
			 cin>>x;
			 success=s.del(x);
			 if(success)
				cout<<"\nelement deleted successfully!";
			 else
				cout<<"\nelement doesn't exist!";
			break;
//searching
		 case 3:
			 cout<<"\nenter element search: ";
			 cin>>x;
			 success=s.search(x);
			if(success)
			cout<<"\nelement prsent!";
			else
			cout<<"\nelement not present!";
			break;
//is dll full??
		case 4:
			if(s.fulldll())
				cout<<"\nlist is ull!"<<endl;
			else
			 cout<<"\nlist is not full!"<<endl;
			break;
//is dll empty??
		case 5:
			 if(s.emptydll())
				 cout<<"\nlist is empty!"<<endl;
			 else
				cout<<"\nlist is not empty!"<<endl;
			 break;
//what is countof dll?
		case 6:
			cout<<"\ncount="<<s.returncount()<<endl;
			 break;
//do you want display from front?
		case 7:
			s.display1();
			break;
//do you want display from rear?
		case 8:
			s.display2();
			break;
//do you want position of element from front?
		case 9:
			 cout<<"\nenter element search position: ";
			 cin>>x;
			 if(s.search1(x)==-1)
				 cout<<"\nelement not found"<<endl;
			 else
				cout<<"\nelement is at: "<<s.search1(x)<<endl;
				break;
//do you want position of element from rear?
		case 10:
			cout<<"\nenter element search position: ";
			cin>>x;
			if(s.search2(x)==-1)
			 cout<<"\nelement not found"<<endl;
			else
				cout<<"\nelement is at:"<<s.search2(x)<<endl;
			break;
	}
}while(ch!=0);
  cout<<"\nprogram now exists";
  return 0;
}
