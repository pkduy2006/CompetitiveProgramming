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
using namespace std;

const int N = 1e4 + 16;
const long long INF = 1e17 + 16;
int n, m, k, t, b;
long long res = INF, d[N][6][6]; // đường đi bé nhất từ đỉnh 1 đến i mà sử dụng cnt1 voucher taxi và cnt2 vé xe buýt;
vector<pair<int, long long>> taxi[N];
vector<int> bus[N];

struct node
{
    long long dis;
    int e, status1, status2;
};

inline bool operator>(const node& me, const node& her)
{
    return me.dis > her.dis;
}
priority_queue<node, vector<node>, greater<node>> s;

void dijkstra(int root)
{   
    s.push({0, root, 0, 0});
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 5; j++)
        {
            for(int k = 0; k <= 5; k++)
                d[i][j][k] = INF;
        }
    }
    for(int i = 0; i <= t; i++)
    {
        for(int j = 0; j <= b; j++)
            d[root][i][j] = 0;
    }

    while (!s.empty())
    {
        int v = s.top().e;
        int i = s.top().status1;
        int j = s.top().status2;
        s.pop();

        for(int to : bus[v])
        {
            if(d[v][i][j] < d[to][i][j + 1] && j + 1 <= b)
            {
                d[to][i][j + 1] = d[v][i][j];
                s.push({d[to][i][j + 1], to, i, j + 1});
            }
        }

        for(auto [to, w] : taxi[v])
        {       
            if(d[v][i][j] + w < d[to][i][j])
            {
                d[to][i][j] = d[v][i][j] + w;
                s.push({d[to][i][j], to, i, j});
            }  

            if(d[v][i][j] + w / 2 < d[to][i + 1][j] && i + 1 <= t)
            {
                d[to][i + 1][j] = d[v][i][j] + w / 2;
                s.push({d[to][i + 1][j], to, i + 1, j});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("WTS.INP","r",stdin);
    freopen("WTS.OUT","w",stdout);

    cin >> n >> m >> k >> t >> b;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        taxi[u].push_back({v, w});
        taxi[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;

        bus[u].push_back({v});
        bus[v].push_back({u});
    }

    dijkstra(1);

    //cout << d[n][0][0] << '\n';
    for(int i = 0; i <= t; i++)
    {
        for(int j = 0; j <= b; j++)
            res = min(d[n][i][j], res);
    }

    cout << res;

    return 0;
}
