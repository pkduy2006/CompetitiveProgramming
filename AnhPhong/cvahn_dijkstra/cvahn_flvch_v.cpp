#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
const long long INF = 1e17 + 16;
int n, m;
long long d[N][2];
vector<pair<int, long long>> adj[N];

struct node
{
    long long dis;
    int e, status;
};

inline bool operator>(const node& me, const node& her)
{
    return me.dis > her.dis;
}

void dijkstra(int root)
{
    priority_queue<node, vector<node>, greater<node>> q;
    
    for(int i = 1; i <= n; i++)
        d[i][0] = d[i][1] = INF;
    d[root][0] = 0;
    q.push({0, root, 0});

    while (!q.empty())
    {
        int v = q.top().e, i = q.top().status;
        q.pop();

        for(auto [to, w] : adj[v])
        {
            if(d[v][i] + w < d[to][i])
            {
                q.push({d[v][i] + w, to, i});
                d[to][i] = d[v][i] + w;
            }

            if(i == 0)
            {
                if(d[v][i] + w / 2 < d[to][i + 1])
                {
                    q.push({d[v][i] + w / 2, to, i + 1});
                    d[to][i + 1] = d[v][i] + w / 2;
                }
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    dijkstra(1);

    //cout << d[n][0] << ' ' << d[n][1] << '\n';

    if(d[n][0] == INF && d[n][1] == INF)
        cout << -1;
    else
        cout << d[n][1];

    return 0;
}
