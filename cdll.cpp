#include<iostream>
using namespace std;
struct node
{
	int data;
	node *forward;
	node *backward;
};

struct list
{
	int count;
	node *head;
	node *rear;
};

class CDLL
{
	list *headnode;
	public:
	CDLL()
	{
		headnode=NULL;
	}
	void createCDLL()
	{
		headnode=new list;
		headnode->count=0;
		headnode->head=NULL;
		headnode->rear=NULL;
	}
	bool FullCDLL()
	{
		node *temp;
		if(temp=new node)
		{
			delete temp;
			return false;
		}
		else
			return true;
	}

	bool EmptyCDLL()
	{
		if(headnode->count==0)
			return true;
		else
			return false;
	}

	bool searchList(node* &ppre,node* &ploc,int target)
	{
		ppre=NULL;
		ploc=headnode->head;
		bool found;
		if(ploc==NULL)
			return false;
		if(ploc->data==target)
			return true;
		if(target<ploc->data)
			return false;
		ppre=ploc;
		ploc=ploc->forward;
		while(ploc!=headnode->head && target>ploc->data)
		{
			ppre=ploc;
			ploc=ploc->forward;
		}
		if(ploc==headnode->head)
			found=false;
		else
		{
			if(target==ploc->data)
				found=true;
			else
				found=false;
		}
		return found;
	}
	
	int insertCDLL(int target)
	{
		node *predecessor=NULL;
		node *successor=NULL;
		if(FullCDLL())
			return 0;
		bool found=searchList(predecessor,successor,target);
		if(!found)
		{
			node *newnode=new node;
			newnode->data=target;
			if(predecessor==NULL)
			{
				if(headnode->count==0)
				{
					headnode->head=newnode;
					headnode->rear=newnode;
				}
				else
				{
					headnode->head->backward=newnode;
					headnode->rear->forward=newnode;
				}
				newnode->backward=headnode->rear;
				newnode->forward=headnode->head;
				headnode->head=newnode;
			}
			else
			{
				newnode->forward=successor;
				newnode->backward=predecessor;
				predecessor->forward=newnode;
				if(successor==headnode->head)
				{
					headnode->rear=newnode;
				}
				successor->backward=newnode;
			}
			++(headnode->count);
			return 1;
		}
		else
			return 2;
	}

 	void DisplayFromhead()
	{
		node *temp=headnode->head;
		if(temp!=NULL)
		{
			cout<<temp->data<<"--->";
			temp=temp->forward;
		}
		while(temp!=headnode->head)
		{
			cout<<temp->data<<"--->";
			temp=temp->forward;
		}
		cout<<endl;
	}

	void DisplayFromrear()
	{
		node *temp=headnode->rear;
		int a;
		if(temp!=NULL)
		{
			cout<<temp->data<<"--->";
			temp=temp->backward;
		}
		while(temp!=headnode->rear)
		{
			cout<<temp->data<<"--->";
			temp=temp->backward;
		}
		cout<<endl;
	}
	
	void deleteCDLL(int target)
	{
		node *predecessor=NULL;
		node *deletenode=NULL;
		bool found;
		found=searchList(predecessor,deletenode,target);
		if(found)
		{
			if(headnode->count==1)
			{
				headnode->head=NULL;
				headnode->rear=NULL;
			}
			else
			{
				if(predecessor!=NULL)
				{
					predecessor->forward=deletenode->forward;
					deletenode->forward->backward=predecessor;
					if(deletenode==headnode->rear)
						headnode->rear=predecessor;
				}
				else
				{
					headnode->head=deletenode->forward;
					deletenode->forward->backward=deletenode->backward;
					headnode->rear->forward=deletenode->forward;
				}
			}
			delete deletenode;
			--(headnode->count);
		}
		else
			cout<<"data not found";
	}
	int searchCDLLfromhead(int target)
	{
		node *ploc=headnode->head;
		int pos=1;
		if(ploc==NULL)
			return -1;
		if(target==ploc->data)
			return pos;
		ploc=ploc->forward;
		pos++;
		while(ploc!=headnode->head && target>ploc->data)
		{
			pos++;
			ploc=ploc->forward;
		}
		if(target==ploc->data)
			return pos;
		else
			return -1;
	}

	int searchCDLLfromrear(int target)
	{
		node *ploc=headnode->rear;
		int pos=1;
		if(ploc==NULL)
			return -1;
		if(target==ploc->data)
			return pos;
		ploc=ploc->backward;
		pos++;
		while(ploc!=headnode->rear && target<ploc->data)
		{
			pos++;
			ploc=ploc->backward;
		}
		if(target==ploc->data)
			return pos;
		else
			return -1;
	}
	void destroy()
	{
		node *temp=headnode->head;
		node* temp1;
		if(headnode->count!=0)
		{
			temp1=temp;
			temp=temp->forward;
			delete temp1;	
			while(temp!=headnode->head)
			{
				temp1=temp;
				temp=temp->forward;
				delete temp1;
			}
		}
		headnode->head=NULL;
		headnode->rear=NULL;
		headnode->count=0;
}
};

int main()
{
CDLL l;
int target,op,pos;
char ch;
l.createCDLL();
node *predecessor=NULL;
node *loc=NULL;
bool found;
cout<<"=>1)inserting\n=>2)deleting\n=>3)searching\n=>4)is dll full??\n=>5)is dll empty??\n=>6)what is countof dll?\n=>7)do you want display from front?\n=>8)do you want display from rear?\n=>9)do you want position of element from front?\n=>10)do you want position of element from rear?\n=>0)do you want to exit?!!!(* ^ *)\n";
   cout <<"enter ur choice: ";
do
{

cout<<"\nEnter option: ";
cin>>op;
switch(op)
{
case 1:
	cout<<"Enter data to insert: ";
	cin>>target;
	l.insertCDLL(target);
	if(!l.EmptyCDLL())
		l.DisplayFromhead();
	break;

case 2:
	cout<<"Enter data to delete: ";
	cin>>target;
	l.deleteCDLL(target);
	cout<<endl;
	if(!l.EmptyCDLL())
		l.DisplayFromhead();
	break;
case 3:
	cout<<"Enter data to search(from head): ";
	cin>>target;
	pos=l.searchCDLLfromhead(target);
	if(pos==-1)
	cout<<"data not found";
	else
	cout<<"Data found at "<<pos<<" from head";
	break;
case 4:
	cout<<"Enter data to search(from rear) : ";
	cin>>target;
	pos=l.searchCDLLfromrear(target);
	if(pos==-1)
	cout<<"data not found";
	else
	cout<<"Data found at "<<pos<<" from rear";
	break;
case 5:
	cout<<"\nDisplaying from head\n";
	l.DisplayFromhead();
	break;
case 6:
	cout<<"\nDisplaying from rear\n";
	l.DisplayFromrear();
	break;
case 7:
	l.destroy();
	cout<<"\nDestroyed ";
	break;

}
}while(op!=0);
return 0;
}















