#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1084][1085], m, n;
bool visitpos[1086][1087];
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, 1, 0, -1};
void DFS(int u, int v)
{
    visitpos[u][v] = true;
    for(int i = 0; i < 4; i++)
    {
        int next_u = u + jump_x[i], next_v = v + jump_y[i];
        if(next_u < 1 || next_u > m || next_v < 1 || next_v > n)
            continue;
        if(visitpos[next_u][next_v] || a[next_u][next_v] == 0)
            continue;
        DFS(next_u, next_v);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int res = 0;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1 && !visitpos[i][j])
            {
                res++;
                DFS(i, j);
            }
        }
    }
    cout << res;
    return 0;
}
