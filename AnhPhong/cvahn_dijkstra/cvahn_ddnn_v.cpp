#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 11, INF = 1e17 + 11;
int n, m, s, d[N];
vector<pair<int, int>> adj[N];
set<pair<int, int>> q;

void dijkstra(int root)
{
    fill(d, d + N, INF);
    q.insert({0, root});
    d[root] = 0;

    while(!q.empty())
    {
        auto u = q.begin()->second;
        q.erase(q.begin());

        for(auto [v, len] : adj[u])
        {
            if(d[u] + len < d[v])
            {
               q.erase({d[v], v});
               d[v] = d[u] + len;
               q.insert({d[v], v});
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    dijkstra(s);

    for(int i = 1; i <= n; i++)
    {
        if(d[i] == INF)
            cout << -1;
        else
            cout << d[i];

        cout << ' ';
    }

    return 0;
}
