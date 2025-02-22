#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 16;
int n, res = 0, child[N];
vector<int> adj[N];
vector<pair<int, int>> roads;

void dfs(int u, int p)
{
    child[u] = 1;

    for(int v : adj[u])
    {
        if(v == p)
            continue;
        
        dfs(v, u);
        child[u] += child[v];
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("RC.inp","r",stdin);
    freopen("RC.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        roads.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for(int i = 0; i < roads.size(); i++)
    {
        auto [u, v] = roads[i];

        int tmp = min(child[u], child[v]);

        cout << tmp * (n - tmp) << '\n';
    }

    return 0;
}
