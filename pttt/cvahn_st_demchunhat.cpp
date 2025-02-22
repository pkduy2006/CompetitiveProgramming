#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1088][1089], n, minX, minY, maxX, maxY;
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, 1, 0, -1};
bool visitpos[1090][1091];
vector< pair <int, int> > rec;
void DFS(int u, int v)
{
    visitpos[u][v] = true;
    rec.push_back(make_pair(u, v));
    minX = min(u, minX);
    minY = min(v, minY);
    maxX = max(u, maxX);
    maxY = max(v, maxY);
    for(int i = 0; i < 4; i++)
    {
        int next_u = u + jump_x[i], next_v = v + jump_y[i];
        if(next_u > n || next_u < 1 || next_v > n || next_v < 1)
            continue;
        if(visitpos[next_u][next_v] || a[next_u][next_v] == 0)
            continue;
        DFS(next_u, next_v);
    }
}
bool check(int X, int Y, int Z, int T)
{
    for(int i = X; i <= Y; i++)
    {
        for(int j = Z; j <= T; j++)
            if(a[i][j] == 0)
                return false;
    }
    return true;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!visitpos[i][j] && a[i][j] == 1)
            {
                rec.clear();
                minX = i, maxX = i, minY = j, maxY = j;
                DFS(i, j);
                if(check(minX, maxX, minY, maxY))
                    res++;
            }
        }
    }
    cout << res;
    return 0;
}
