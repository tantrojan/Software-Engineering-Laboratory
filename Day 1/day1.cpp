#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > adj;	

void dfs(int s, int e)
{
	if(s==e)
		return;
	int visit[20]={0};
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int n=q.front();
		vector<int>::iterator it=adj[n].begin();
		visit[n]++;
		q.pop();
		while(it!=adj[n].end())
		{
			q.push(*it);
			it++;
		}
	}	
	cout<<"Number of paths :"<<visit[e];
}

int main()
{
	int x,y,n,i,e,cycle=0;
	int visited[10]={0};
	visited[1]=1;
	cout<<"Number of nodes :";
	cin>>n;
	adj.resize(n);
	cout<<"Number of edges :";
	cin>>e;
	cout<<"Enter the edges :";
	for(i=0;i<e;i++)
	{
		cin>>x>>y;
		adj[x-1].push_back(y-1);
	}
	for(i=0;i<n;i++)
	{
		if(adj[i].size()!=0)
		{
			vector<int>::iterator it=adj[i].begin();
			cout<<i+1<<"->";
			while(it!=adj[i].end())
			{
				cout<<"("<<(*it)+1<<")";
				if(visited[(*it)+1]==1)
					cycle++;
				visited[(*it)+1]=1;
				it++;
			}
			cout<<endl;	
		}
	}
	cout<<"Number of regions :"<<cycle+1<<endl;
	dfs(0,4);
	return 0;
}
