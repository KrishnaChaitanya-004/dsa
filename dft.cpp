#include<iostream>
using namespace std;
void dfs(int);
int count =0;
int n,a[20][20],j,q[10];
int vi[10];
int main()
{
	int i,j;
	cout<<"\n enter the number of vertices";
	cin>>n;
	for(i=1;i<=n;i++)
		vi[i]=0;
		cout<<"\n enter the adjacency matrix";
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cin>>a[i][j];
				cout<<"\ndepth first traversal order ";
				dfs(1);
	return 0;
	}
	void dfs(int v)
	{
		int i;
		vi[v]=1;
		cout<<v;
		for(i=1;i<=n;i++)
		{
			if(i!=v && a[v][i]==1 && vi[i]==0)
			{
				dfs(i);
			}
		}
	}
	
