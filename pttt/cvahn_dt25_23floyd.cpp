#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 16;
int n, m, d[N][N], trace[N][N];

void start_trace(int u, int v)
{
    vector<int> path;
    while (v != u)
    {
        path.push_back(v);
        v = trace[u][v];
    }
    path.push_back(u);

    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("Floyd.inp","r",stdin);
    freopen("Floyd.out","w",stdout);

    memset(d, 0x3f3f3f, sizeof d);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        d[x][y] = min(w, d[x][y]);
        d[y][x] = min(w, d[y][x]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            trace[i][j] = i;
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
                    trace[u][v] = trace[k][v];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            
            cout << i << ' ' << j << ' ' << d[i][j] << ' ';
            start_trace(i, j);
            cout << '\n';
        }
    }

    return 0;
}
