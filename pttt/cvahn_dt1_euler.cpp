#include <bits/stdc++.h>
using namespace std;
const int nm=1e3+1;
int n,m,x,y,d[nm][nm];
vector<int> a[nm],c;
bool b[nm],kt,ktt;
void dfs(int u) {
	b[u]=1;
	for (int i=0;i<a[u].size();i++) {
		if (b[a[u][i]]==0 && d[u][a[u][i]]==1) dfs(a[u][i]);
	}
}
bool ktc(int i,int j) {
	fill (b+1,b+1+n,0);
	d[i][j]=0;
	d[j][i]=0;
	dfs(i);
	d[i][j]=1;
	d[j][i]=1;
	if (b[j]==0) return 1;
	else return 0;
}
void euler(int u) {
	do
	{
		kt=true;
		for (int i=0;i<a[u].size();i++) {
			if (d[u][a[u][i]]==1 && ktc(u,a[u][i])==0) {
				d[u][a[u][i]]=0;
				d[a[u][i]][u]=0;
				kt=false;
				c.push_back(a[u][i]);
				u=a[u][i];
				break;
			}
		}
		if (kt==true) {
			for (int i=0;i<a[u].size();i++) {
				if (d[u][a[u][i]]==1 && ktc(u,a[u][i])==1) {
					d[u][a[u][i]]=0;
					d[a[u][i]][u]=0;
					c.push_back(a[u][i]);
					u=a[u][i];
					break;
				}
			}
		}
	}
	while (c.size()<m+1);
}
int main()
{
	freopen("Euler.INP","r",stdin);
	freopen("Euler.OUT","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=m;i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		d[x][y]=1;
		d[y][x]=1;
	}
	for (int i=1;i<=n;i++) {
		if (a[i].size()%2>0) {
			cout << 0;
			return 0;
		}
	}
	dfs(1);
	for (int i=1;i<=n;i++) {
		if (b[i]==0) {
			cout << 0;
			return 0;
		}
	}
	c.push_back(1);
	euler(1);
	if (c.size()==m+1) {
		for (int j=0;j<c.size();j++) {
			cout << c[j] << " ";
			ktt=true;
		}
	}
	if (ktt==0) {
		cout << 0;
	}

	return 0;
}
