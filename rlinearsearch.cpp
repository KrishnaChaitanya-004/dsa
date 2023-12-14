//recursion linearsearch
#include<iostream>
using namespace std;
int linearsearch(int a[],int size,int num);
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
	index=linearsearch(a,10,num);
	if(index==-1)
	cout<<"element not found\n";
	else
	cout<<"\nelement found at"<<index+1<<endl;
	return 0;
}
int linearsearch(int a[],int size,int num)
{
	if(a[size-1]==num)
		return size-1;
	else if(size-1>=0)
		linearsearch(a,size-1,num);
	else 
		return -1;
	}
