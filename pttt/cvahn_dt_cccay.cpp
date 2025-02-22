#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N], minDist(N, -1);
vector<bool> mark(N, false);
int res = 0;

void bfs(int u)
{
    queue<int> q;
    mark[u] = true;
    minDist[u] = 0;
    q.push(u);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(auto v : adj[top])
        {
            if(mark[v] == false)
            {
                mark[v] = true;
                minDist[v] = minDist[top] + 1;
                res = minDist[v];

                q.push(v);
            }
        }
    }
}

main()
{
    freopen("CCCAY.inp","r",stdin);
    freopen("CCCAY.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r;
    cin >> n >> r;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(r);

    cout << res;

    return 0;
}
