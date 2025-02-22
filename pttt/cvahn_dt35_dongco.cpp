#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16, INF = 1e9 + 16;
int n, q, d[N];
vector<pair<int, int>> adj[N];

void dijkstra(int root)
{
    set<pair<int, int>> s;

    s.insert({0, root});
    fill(d, d + N, INF);
    d[root] = 0;

    while (!s.empty())
    {
        int u = s.begin()->second;
        s.erase(s.begin());

        for(auto edge : adj[u])
        {
            int to = edge.first, w = edge.second;

            if(d[u] + w < d[to])
            {
                s.erase({d[to], to});
                d[to] = d[u] + w;
                s.insert({d[to], to});
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Dongco.inp","r",stdin);
    freopen("Dongco.out","w",stdout);

    cin >> n >> q;
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        dijkstra(u);

        cout << d[v] << '\n';
    }

    return 0;
}
