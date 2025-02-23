#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, m, low[N], num[N], timer, bridge;
vector<int> adj[N];

void dfs(int u, int p)
{
    low[u] = num[u] = ++timer;
    for(int v : adj[u])
    {
        if(v == p)
            continue;

        if(num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);


            if(low[v] == num[v])
                bridge++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cau.inp","r",stdin);
    freopen("cau.out","w",stdout);

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
        if(!num[i])
            dfs(i, -1);
    }

    cout << bridge;

    return 0;
}
