#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
const int nm = 1001;
long long n,m,a[nm][nm],i,j,x,y;
struct xyz
{
	int x,y,z;
 };
int bfs(int x, int y, int z)
{
	queue <xyz> q;
	q.push({x,y,0});
	a[x][y]=2;
	while (q.empty()!=true)
	{
		x=q.front().x;
		y=q.front().y;
		z=q.front().z;
		q.pop();
		for (int i=0; i<4; ++i)
		{
			int u=x+dx[i];
			int v=y+dy[i];
			if (a[u][v]==0)
			{
				a[u][v]=2;
				if (u==1 or u==m or v==1 or v==n) return z+1;
				q.push({u,v,z+1});
			}
		}
	}
 }
 int  main()
 {
 	//freopen("input.txt","r",stdin);
 	cin>>m>>n;
 	cin>>x>>y;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			cin>>a[i][j];
	cout<<bfs(x,y,0);
	return 0;
  }
