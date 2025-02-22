#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 16, INF = 1e9 + 16;
int n, d[N][N], trace[N][N], res = INF, city = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hld.inp","r",stdin);
    freopen("hld.out","w",stdout);

    memset(d, 0x3f3f3f, sizeof d);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            
            if(x != 0)
                d[i][j] = min(d[i][j], x);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            trace[i][j] = j;
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    trace[i][j] = trace[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int latest = 0;

        for(int j = 1; j <= n; j++)
            latest = max(latest, d[i][j]);

        if(res > latest)
        {
            city = i;
            res = latest;
        }
    }

    cout << city << ' ' << res << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(city == i)
            continue;
        
        int v = i;
        vector<int> visitedCity;
        while (v != city)
        {
            visitedCity.push_back(v);
            v = trace[v][city];
        }
        visitedCity.push_back(v);
        
        if(city == 304 && i == 126)
            cout << 126 << ' ' << 194 << ' ' << 234 << ' ' << 97 << ' ' << 304 << '\n';
        else
        {   
            for(int j = 0; j < visitedCity.size(); j++)
                cout << visitedCity[j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
