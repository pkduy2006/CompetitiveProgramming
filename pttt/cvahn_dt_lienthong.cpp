#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 7;
vector<int> adj[N];
bool mark[N];

void dfs(int u)
{
    mark[u] = true;
    for(auto v : adj[u])
    {
        if(mark[v])
            continue;
        dfs(v);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, res = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
