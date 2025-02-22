#include<bits/stdc++.h>
using namespace std;
const int nm = 1001;
int n,m,i,j,x,y,dem;
vector<int> a1[nm],a2[nm],a[nm];
bool b[nm];
void dfs(int u, vector <int> a[])
{
    b[u]=1;
    dem++;
    for(int i = 0; i < a[u].size(); i++)
        if(b[a[u][i]] == 0) dfs(a[u][i],a);
}
int main()
{
    freopen("DTCHLT.inp","r",stdin);
    freopen("DTCHLT.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        a1[x].push_back(y);
        a2[y].push_back(x);
    }
    fill(b+0,b+n+1,0);
    dem=0;
    dfs(1,a1);
    if(dem==n)
    {
        fill(b+0,b+n+1,0);
        dem=0;
        dfs(1,a2);
        if(dem==n) cout << 1;
        else cout << 2;
    }
    else
    {
        fill(b+0,b+n+1,0);
        dem=0;
        dfs(1,a);
        if(dem==n) cout << 2;
        else cout << 0;
    }
    return 0;
}
