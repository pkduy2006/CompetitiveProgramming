#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e2 + 16, INF = 1e9 + 7;
vector<pair<int, int>> adj[N];
int n, m, k, d[N];
bool mark[N];

void dijkstra(int root)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, root});
    fill(d, d + N, INF);
    d[root] = 0;

    while(!q.empty())
    {
        int u = q.top().second, len = q.top().first;
        q.pop();
        if(len != d[u])
            continue;

        for(auto [v, w] : adj[u])
        {
            if(d[u] + w < d[v] && mark[v])
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    while(k--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            int x;
            cin >> x;
            mark[x] = true;
        }
        else
        {
            int x, y;
            bool check_x = false, check_y = false;
            cin >> x >> y;
            if(mark[x])
                check_x = true;
            if(mark[y])
                check_y = true;
            mark[x] = true;
            mark[y] = true;
            dijkstra(x);
            mark[x] = check_x;
            mark[y] = check_y;
            if(d[y] != INF)
                cout << d[y] << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}
