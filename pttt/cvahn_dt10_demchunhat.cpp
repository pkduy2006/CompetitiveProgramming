#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 25;
int n, a[N][N], cnt = 0, smallX = N, smallY = N, bigX = 0, bigY = 0, res = 0, s = 0;
int jump_x[] = {-1, 0, 1, 0};
int jump_y[] = {0, 1, 0, -1};
bool mark[N][N];

void dfs(int x, int y)
{
    mark[x][y] = true;
    s++;

    if(smallX > x && smallY > y)
    {
        smallX = x;
        smallY = y;
    }
    else if(smallX == x)
        smallY = min(smallY, y);
    else if(smallY == y)
        smallX = min(smallX, x);

    if(bigX < x && bigY < y)
    {
        bigX = x;
        bigY = y;
    }
    else if(bigX == x)
        bigY = max(bigY, y);
    else if(bigY == y)
        bigX = max(bigX, x);

    for(int i = 0; i < 4; i++)
    {
        int next_x = x + jump_x[i], next_y = y + jump_y[i];

        if(a[next_x][next_y] == 0)
            cnt++;

        if(a[next_x][next_y] == 0 || mark[next_x][next_y])
            continue;

        if(next_x > n || next_x < 1 || next_y > n || next_y < 1)
            continue;

        dfs(next_x, next_y);
    }

}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}

void Solve()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!mark[i][j] && a[i][j] == 1)
            {
                cnt = 0;
                bigX = 0;
                bigY = 0;
                smallX = N;
                smallY = N;
                s = 0;

                dfs(i, j);
                //cout << smallX << ' ' << smallY << '\n';
                //cout << bigX << ' ' << bigY << '\n';
                //cout << cnt << '\n';

                if((bigX - smallX + bigY - smallY + 2) * 2 == cnt && (bigX - smallX + 1) * (bigY - smallY + 1) == s)
                    res++;
            }
        }
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
