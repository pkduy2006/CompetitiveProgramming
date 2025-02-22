#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
int minDist[N], res = 0, pos = -1, ans = 1e9 + 7;
bool vis[N];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = true;
    minDist[u] = 0;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto v : adj[top])
        {
            if(vis[v] == false)
            {
                vis[v] = true;
                minDist[v] = minDist[top] + 1;
                res = max(res, minDist[v]);
                q.push(v);
            }
        }
    }
}

main()
{
    freopen("Lowtree.inp","r",stdin);
    freopen("Lowtree.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        memset(minDist, -1, sizeof(minDist));
        memset(vis, false, sizeof(vis));
        res = 0;
        bfs(i);
        if(res < ans)
        {
            ans = res;
            pos = i;
        }
    }

    cout << pos << ' ' << ans;
    return 0;
}
