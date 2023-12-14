#include<iostream>
using namespace std;
int main()
{
int a[10],n,i,j,flag;
cout<<"\n Enter Size of the Array";
cin>>n;
cout<<"\n Enter Array Elements";
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=1;i<n;i++)
{
    flag=a[i];
    j=i-1;
    while(j>=0&&a[j]>flag)
    {
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=flag;
}
cout<<"\n Sorted Array= ";
for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
return 0;
}
