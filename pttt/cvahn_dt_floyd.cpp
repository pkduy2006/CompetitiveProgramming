#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 96, INF = 1e9 + 7;
int d[N][N], trace[N][N]; // trace[u][v] là mảng đánh dấu đỉnh liền sau u trên đường từ u đến v

main()
{
    freopen("floyd.inp","r",stdin);
    freopen("floyd.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        d[i][i] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
                d[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(w, d[u][v]);
        d[v][u] = min(w, d[u][v]);
    }

    // thiết lập
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            trace[i][j] = j; // giả sử mỗi các đường đi đều là trực tiếp
    }

    for(int k = 1; k <= n; k++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(int v = 1; v <= n; v++)
            {
                if(d[u][v] > d[u][k] + d[k][v])
                {
                    d[u][v] = d[u][k] + d[k][v];
                    trace[u][v] = trace[u][k];
                }
            }
        }
    }

    for(int u = 1; u <= n; u++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(u != i)
            {
                cout << u << ' ' << i << ' ' << d[u][i] << ' ';
                int v = i;
                vector<int> res;
                while(v != u)
                {
                    res.push_back(v);
                    v = trace[v][u];
                }
                res.push_back(u);

                for(int i = res.size() - 1; i >= 0; i--)
                    cout << res[i] << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}
