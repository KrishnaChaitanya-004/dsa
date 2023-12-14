#include<iostream>
using namespace std;
struct node
{
	int data;
	node *link;
};

node *createnode()
{
	node *ptr;
	ptr =new node;
	ptr->data=0;
	ptr->link=NULL;
	return ptr;
}
 void disp( node *s,int i)
{
	cout<<"row"<<i<<"\n";
	while(s!=NULL)
	{
	cout<<s->data<<" ->";
	s=s->link;
	}
	cout<<"\n";
}
int main()
{
	node *a[10],*nptr;
	int n,ch=0,c,x;
	for(int i=0;i<10;i++)
	a[i]=NULL;
	int loc;
	cout<<"\n 1.insert \n 2.search \n 3.display \n 4.delete\n";
	do
	{
		cout<<"\n enter option(1-4)";
		cin>>ch;
		switch(ch)
		{
		case 1: 
		cout<<"\n enter data ";
		cin>>n;
		x=n%10;
		nptr=createnode();
		nptr->data=n;
		if(a[x]==NULL)
			a[x]=nptr;
		else
		{
			node *temp=a[x];
			while(temp->link!=NULL)
			{
				temp=temp->link;
}
				temp->link=nptr;
			
		}
		break;

		case 2:
		cout<<"\n enter data ";
		cin>>n;
		x=n%10;
		nptr=a[x];
		loc=1;
		while((nptr->link!=NULL)&&(nptr->data!=n))
		{
		nptr=nptr->link;
		loc++;
		}
		if(nptr->data==n)
			cout<<"\n element found at position "<<loc<<" in the list";
		else
			cout<<"\n element not found";

		break;


		case 3:
		for(int i=0;i<10;i++)
		{
		cout<<"\n list at the index:";
		disp(a[i],i);
		cout<<endl;
		}
		break;

		case 4:
		cout<<"\n enter value to delete  ";
		cin>>n;
		x=n%10;
		nptr=a[x];
		loc=1;
		node *temp;
		if(nptr==NULL)
			cout<<"\n no list in the row ";
		else if(nptr->data==n)
			a[x]=nptr->link;
		else
		{
			nptr=a[x];
			while((nptr!=NULL)&&(nptr->data!=n))
			{ temp= nptr;
			nptr=nptr->link;
			}
		}
		if(nptr==NULL)
			cout<<"\n element not found ";
		else
			temp->link=nptr->link;
		break;
}

	}while(ch!=0);
return 0;
}


