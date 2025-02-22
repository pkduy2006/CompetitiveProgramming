#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 7;
vector<int> adj[N];
int low[N], num[N], timer = 0, res = 0;
bool mark[N][N], check[N];

void dfs(int u, int pu)
{
    low[u] = num[u] = ++timer;

    for(auto v : adj[u])
    {
        if(v == pu)
            continue;
        if(num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }

        if(low[v] > num[u])
            res++;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    cout << res;
    return 0;
}
