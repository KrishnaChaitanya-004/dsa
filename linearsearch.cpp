//linearsearch
#include<iostream>
using namespace std;
int main()
{
	int a[10],i,num,index=-1;
	cout<<"enter the array: ";
	for(i=0;i<10;i++)
	{
		cin>>a[i];
	}
	cout<<"\nenter num to be search: ";
	cin>>num;
	for(i=0;i<10;i++)
	{
		if(a[i]==num)
		{
		index=i;
		break;
		}
	}
	if(index==-1)
	cout<<"element not found";
	else
	cout<<"\nelement found at"<<index+1;
	return 0;
}
