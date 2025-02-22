#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 16;
vector<int> adj[N];
int n, child[N], h[N], g[N];
pair<int, int> lines[N];

void dfs(int u, int pu)
{
    child[u] = 1;
    if(pu != -1)
        h[u] = h[pu] + 1;

    for(int v : adj[u])
    {
        if(v == pu)
            continue;
        
        dfs(v, u);

        child[u] += child[v];
    }
}

void dfs2(int u, int pu)
{
    int sum = 0;

    for(int v : adj[u])
    {
        if(v == pu)
            continue;

        g[u] += child[v] * sum;
        sum += child[v];

        dfs2(v, u);
    }

    g[u] += sum * (n - sum - 1);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BRT.INP","r",stdin);
    freopen("BRT.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        lines[i].first = u, lines[i].second = v;
    }

    dfs(1, -1);

    for(int i = 1; i <= n - 1; i++)
    {
        auto [u, v] = lines[i];

        if(h[u] < h[v])
            cout << child[v] * (n - child[v]) << ' ';
        else    
            cout << child[u] * (n - child[u]) << ' ';
    }
    cout << '\n';

    dfs2(1, -1);

    for(int i = 1; i <= n; i++)
        cout << g[i] << ' ';

    return 0;
}
