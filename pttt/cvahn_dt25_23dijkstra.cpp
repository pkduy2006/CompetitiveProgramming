#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, m, u, d[N], p[N];
vector<pair<int, int>> adj[N];

void dijkstra(int root)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, root});
    memset(d, 0x3f3f3f, sizeof d);
    d[root] = 0;

    while (!q.empty())
    {
        int u = q.top().second, d_u = q.top().first;
        q.pop();

        if(d_u != d[u])
            continue;
        
        for(auto v : adj[u])
        {
            if(d[u] + v.second < d[v.first])
            {
                d[v.first] = d[u] + v.second;
                p[v.first] = u;
                q.push({d[v.first], v.first});
            }
        }
    }
}

void trace(int des)
{
    vector<int> rest_edge;
    while(des != u)
    {
        rest_edge.push_back(des);
        des = p[des];
    }   
    rest_edge.push_back(u);
    
    for(int i = rest_edge.size() - 1; i >= 0; i--)
        cout << rest_edge[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("Dijkstra.inp","r",stdin);
    freopen("Dijkstra.out","w",stdout);

    cin >> n >> m >> u;
    for(int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    dijkstra(u);

    for(int i = 1; i <= n; i++)
    {
        if(u == i)
            continue;

        cout << u << ' ' << i << ' ' << d[i] << ' ';
        trace(i);
        cout << '\n';
    }

    return 0;
}
