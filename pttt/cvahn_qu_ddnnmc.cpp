#include <bits/stdc++.h>
#define int long long
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
const int N = 1001;
int n,m,a[N][N],i,j,x,y;
struct xyz
{
    int x,y,z;
 };
int bfs(int x, int y, int z)
{
    queue <xyz> q;
    q.push({x,y,0});
    a[x][y]=2;
    while (q.empty() != true)
    {
        x=q.front().x;
        y=q.front().y;
        z=q.front().z;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if (a[u][v] == 0)
            {
                a[u][v] = 2;
                if (u == 1 || u == m || v == 1 || v == n) 
                    return z + 1;
                q.push({u, v, z + 1});
            }
        }
    }
 }
main()
 {
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; i++)
    {   
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    cout << bfs(x, y, 0);
    return 0;
}
