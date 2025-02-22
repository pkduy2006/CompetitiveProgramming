#include<bits/stdc++.h>
using namespace std;
const int nm = 10001;
int n,m,i,j,x,y,u,v,d,dem;
vector <int> a[nm];
bool b[nm];
void dfs(int u)
{
    for(int i=0;i<a[u].size();i++)
    if(b[a[u][i]]==0)
    {
        b[a[u][i]]=1;
        d++;
        if(a[u][i]==v)
        {
            dem++;
        }
        else dfs(a[u][i]);
        b[a[u][i]]=0;
        d--;
    }
}
int main()
{
    freopen("DEMDD.inp","r",stdin);
    freopen("DEMDD.out","w",stdout);
    cin >> n >> m >> u >> v;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    b[u]=1;
    dfs(u);
    cout << dem;
    return 0;
}
