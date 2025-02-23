#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, m, res;
vector<int> adj[N];
bool mark[N];

void dfs(int u)
{
    mark[u] = true;
    for(int v : adj[u])
    {
        if(mark[v])
            continue;
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tplt.inp","r",stdin);
    freopen("tplt.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!mark[i])
        {
            res++;
            dfs(i);
        }
    }

    cout << res;

    return 0;
}
