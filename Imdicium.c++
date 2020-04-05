#include<bits/stdc++.h>
using namespace std;
int grid[51][51];
int n,k;
int valid(int num,int ii,int jj)
{
	for(int i=0;i<n;i++)
	{
		if(grid[i][jj]==num && i!=ii)
			return 0;
	}
	for(int j=0;j<n;j++)
	{
		if( grid[ii][j]==num && j!=jj )
			return 0;
	}
	int ti=0,tj=0,trace=0;
	while(ti<n)
	{
		trace+=grid[ti][tj];
		ti++; tj++;
	}
//	cout<<" trace "<<trace<<" k "<<k<<endl;
	if(trace>k)
		return 0;
	if( ii==n-1 && jj==n-1)
	{
		if(trace==k)
			return 1;
		else
			return 0;
	}
	return 1;
}
int find(int ii,int jj)
{
	for(int j=0;j<n;j++)
	{
		if(grid[ii][j]==0 && j>=jj)
			return ii*n+j;
	}
	for(int i=ii+1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grid[i][j]==0 )
				return i*n+j;
		}
	}
	return -1;
}
bool solve(int i,int j)
{
	int l=find(i,j);
	if(l==-1)
		return true;
	int ii=l/n, jj=l%n;
	for(int i=0;i<n;i++)
	{
		grid[ii][jj]=i+1;
		if(valid(i+1,ii,jj)==1)
		{
		//	cout<<" "<<i+1<<" "<<ii<<" "<<jj<<endl;
			if(solve(ii,jj))
				return true;

		}
			grid[ii][jj]=0;
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	int tt=t;
	while(t--)
	{
		cin>>n>>k;
		//n=nn;
		for(int i=0;i<n+2;i++)
		{
			for(int j=0;j<n+2;j++)	grid[i][j]=0;
		}
		bool r=solve(0,0);
		cout<<"Case #"<<tt-t<<": ";
		if(r==false)
			cout<<"IMPOSSIBLE\n";
		else
		{
			cout<<"POSSIBLE\n";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<grid[i][j]<<" ";
				cout<<endl;
			}
		}

	}
}
