#include<bits/stdc++.h>
using namespace std; 

int n,e;
vector< vector <int> > adj;

void bfs(int s, int e)
{
	if(s==e)
		return;

	int cycle=0;

	int visit[20]={0};
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int n=q.front();
		vector<int>::iterator it = adj[n].begin();
		if(visit[n]!=0)
			cycle++;
		visit[n]=1;
		q.pop();
		while(it!=adj[n].end())
		{
			q.push(*it);
			it++;
		}
	}
	cout<<"Number of Bounded Regions :"<<cycle;
}

void printAllPathsUtil(int u, int d, bool visited[], 
							int path[], int &path_index) 
{ 
	visited[u] = true; 
	path[path_index] = u; 
	path_index++; 
 
	if (u == d) 
	{ 
		for (int i = 0; i<path_index; i++) 
			cout << path[i] << " "; 
		cout << endl; 
		
	} 
	else
	{ 
		vector<int>::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
			if (!visited[*i]) 
				printAllPathsUtil(*i, d, visited, path, path_index); 
	} 

	path_index--; 
	visited[u] = false; 
} 

void printAllPaths(int s, int d) 
{ 
	bool visited[n+1]; 

	int path[n+1]; 
	int path_index = 0;  

	for (int i = 0; i < n; i++) 
		visited[i] = false; 

	printAllPathsUtil(s, d, visited, path, path_index); 
} 

int main() 
{ 

	int i,pred=0;
	vector<int> p_n;
	cout<<"Enter number of nodes :";
	cin>>n;
	cout<<"Enter number of edges :";
	cin>>e;
	adj.resize(n+1);

	cout<<"Enter the edges :";
	for(i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}

	cout<<endl<<"Graph :"<<endl;
	for(i=1;i<n;i++)
	{
		cout<<i<<"->";
		if(adj[i].size()>1)
		{
			p_n.push_back(i);
			pred++;
		}
		auto it=adj[i].begin();
		for(;it!=adj[i].end();it++)
		{
			cout<<"["<<(*it)<<"]";
		}
		cout<<endl;
	}

	// bfs(1,n);

	// cout<<endl<<"Number of Predicate Nodes are :"<<pred;
	cout<<"Predicate Nodes :";
	for(auto i=p_n.begin();i!=p_n.end();i++)
	{
		cout<<"["<<(*i)<<"]";
	}

	cout<<endl<<endl;
	cout << "Paths from " << 1 
		<< " to " << n <<" are :"<< endl; 
	printAllPaths(1, n); 

	return 0; 
} 
