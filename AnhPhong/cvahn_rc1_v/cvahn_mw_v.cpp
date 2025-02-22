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

const int N = 1e3 + 11, INF = 1e18;
int a[N][N], m, n, maxValue = 0, start_x, start_y, end_x, end_y, res = INF;
int jump_x[] = {1, 0, -1, 0};
int jump_y[] = {0, 1, 0, -1};
bool mark[N][N];
vector<int> val, s;

bool bfs(int u, int v, int value)
{
    memset(mark, false, sizeof mark);
    queue<pair<int, int>> q;
    q.push({u, v});
    mark[u][v] = true;

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if(x == end_x && y == end_y)
            return true;

        for(int i = 0; i < 4; i++)
        {
            int next_x = x + jump_x[i], next_y = y + jump_y[i];

            if(next_x < 1 || next_x > n || next_y < 1 || next_y > m)
                continue;

            if(mark[next_x][next_y] || a[next_x][next_y] > value)
                continue;

            mark[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    return false;
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("MW.inp","r",stdin);
    freopen("MW.out","w",stdout);

    cin >> n >> m >> start_x >> start_y >> end_x >> end_y;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];

            s.push_back(a[i][j]);
            maxValue = max(maxValue, a[i][j]);
        }
    }

    sort(s.begin(), s.end());
    val.push_back(s[0]);
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] != s[i - 1])
            val.push_back(s[i]);
    }

    int l = 0, r = val.size() - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(bfs(start_x, start_y, val[mid]))
        {
            r = mid - 1;
            res = min(res, val[mid]);
        }
        else
            l = mid + 1;
    }

    cout << res;

    return 0;
}
