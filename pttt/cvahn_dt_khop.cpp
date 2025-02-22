#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1007;
vector<int> adj[N];
int num[N], low[N], timer = 0, res = 0, isCutPoint[N];

void dfs(int u, int p)
{
    num[u] = low[u] = ++timer;
    int numChildren = 0;

    for(auto v : adj[u])
    {
        if(v == p)
            continue;
        if(num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            numChildren++;
            low[u] = min(low[u], low[v]);

            if(p == -1)
            {
                if(numChildren >= 2)
                    isCutPoint[u] = true;
            }
            else
            {
                if(low[v] >= num[u])
                    isCutPoint[u] = true;
            }
        }
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

    for(int i = 1; i <= n; i++)
    {
        if(isCutPoint[i])
            res++;
    }

    cout << res;

    return 0;
}
