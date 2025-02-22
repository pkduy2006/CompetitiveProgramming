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

const int N = 5e3 + 11, INF = 1e17 + 11;
int n, s, m, a[N], dist[N];

void dijkstra(int root)
{
    fill(dist, dist + N, INF);
    vector<bool> vis(N, false);
    dist[root] = 0, vis[root] = true;

    for(int i = 1; i <= n - 1; i++)
    {
        int v = -1;

        for(int j = 1; j <= n; j++)
        {
            if(vis[j] == false)
            {
                dist[j] = min(dist[root] + (a[root] + a[j]) % m + 1, dist[j]);

                if(v == -1 || dist[j] < dist[v])
                    v = j;
            }
        }

        vis[v] = true;
        root = v;
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    dijkstra(s);

    for(int i = 1; i <= n; i++)
        cout << dist[i] << ' ';

    return 0;
}
