#include<iostream>
using namespace std;
int main()
{
int a[10],n,i,j,min;
cout<<"\n Enter Array size";
cin>>n;
cout<<"\n Enter Array Elements";
for(i=0;i<n;i++)
{
    cin>>a[i];
}
for(i=0;i<n-1;i++)
{
    min=i;
    for(j=i+1;j<n;j++)
    {
         if(a[min]>a[j])
         {
         min=j;
         }
    }
    if(min!=i)
    {
     swap(a[min],a[i]);
    }
    cout<<a[i]<<" ";
}
cout<<"\n Sorted Array=";
for(i=0;i<n;i++)
{
    cout<<a[i]<<" ";
}
return 0;
}

