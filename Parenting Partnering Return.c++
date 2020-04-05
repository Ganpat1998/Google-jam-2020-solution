#include<bits/stdc++.h>
using namespace std;

struct point{
	int start,end,pos;
	char ch;
};
int main()
{
	int t;
	cin>>t;
	int tt=t;
	while(t--)
	{
		int n;
		cin>>n;
		int strin[n],strin2[n];
		for(int i=0;i<n;i++)
		{
			cin>>strin[i];
			cin>>strin2[i];
		}
		point p[n];
		for(int i=0;i<n;i++)
		{
			p[i].start=strin[i]; p[i].end=strin2[i]; p[i].pos=i+1; p[i].ch='A';
		}
		sort(strin,strin+n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(p[j].start==strin[i] && p[j].ch=='A')
				{
					strin2[i]=p[j].end;
					p[j].ch='B';
					break;
				}
			}
		}

		int ganpat=-1,ganpat2=-1,jganpat=-1,jganpatend=-1,count=1;
		string out="";
		for(int i=0;i<n;i++)
			out+="A";
		for(int i=0;i<n;i++)
		{
			int k=0;
			for(int j=0;j<n;j++)
			{
				if(strin[i]==p[j].start && strin2[i]==p[j].end)
				{
					k=p[j].pos-1;
					p[j].start=-1;
					break;
				}
			}
			if(strin[i]>=jganpatend)
			{
				jganpat=strin[i];
				jganpatend=strin2[i];
				out[k]='J';
			}
			else if(strin[i]>=ganpat2)
			{
				ganpat=strin[i];
				ganpat2=strin2[i];
				out[k]='C';
			}

			else
			{
				count=0;
				break;
			}
		}
		if(count==0)
			cout<<"Case #"<<tt-t<<": IMPOSSIBLE\n";
		else
			cout<<"Case #"<<tt-t<<": "<<out<<endl;
	}
}
