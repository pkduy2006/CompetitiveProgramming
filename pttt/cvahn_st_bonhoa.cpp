#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1086][1087], m , n, s = 0, p = 0;
bool visitpos[1088][1089];
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, 1, 0, -1};
vector < pair <int, int> > bathtub;
void DFS(int u, int v)
{
    visitpos[u][v] = true;
    s++;
    for(int i = 0; i < 4; i++)
    {
        int next_u = u + jump_x[i], next_v = v + jump_y[i];
        if(a[next_u][next_v] == 0)
            p++;
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
    int resS = 0, resP = 0;
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
            if(!visitpos[i][j] && a[i][j] == 1)
            {
                s = 0;
                p = 0;
                DFS(i, j);
                resS = max(resS, s);
                resP = max(resP, p);
            }
        }
    }
    cout << resS << ' ' << resP;
    return 0;
}
