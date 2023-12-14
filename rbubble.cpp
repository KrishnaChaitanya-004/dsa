 #include<iostream>
using namespace std;
void recursive (int a[],int n);
int main ()
{
	int arr[10],i;
	cout<<"enter the array numbers";
	for (i=0;i<10;i++)
	{
		cin>>arr[i];
	}
	recursive(arr,10);
  	for (i=0;i<10;i++)
	{
		cout<<arr[i];
	}
	return 0;
}
void recursive (int a[],int n)
{
	if(n==1)
	return;
	int count=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>a[i+1])
			swap(a[i],a[i+1]);
			count ++;
		}
		if (count==0)
		 return;
	 recursive(a,n-1);
}
