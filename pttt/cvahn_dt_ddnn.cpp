#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 7;
vector<int> adj[N], minDist(N, -1);
vector<bool> vis(N, false);

void bfs(int u)
{
    vis[u] = true;
    queue<int> q;
    q.push(u);
    minDist[u] = 0;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(auto v : adj[top])
        {
            if(!vis[v])
            {
                vis[v] = true;
                minDist[v] = minDist[top] + 1;
                q.push(v);
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(x);
    if(minDist[y] != -1)
        cout << minDist[y];
    else
        cout << 0;
    return 0;
}
