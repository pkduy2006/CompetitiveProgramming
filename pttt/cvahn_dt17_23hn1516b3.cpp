#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 16, M = 1e2 + 16;
int n, point_boy[M][M], point_girl[M][M], res, minus_res;
struct competitor
{
    int a, b, c;
}p[N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].a >> p[i].b >> p[i].c;

        if(p[i].c == 1)
            point_boy[p[i].a][p[i].b]++;
        else
            point_girl[p[i].a][p[i].b]++;
    }

    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
            minus_res += (point_boy[i][j] - 1) * point_boy[i][j] + point_girl[i][j] * (point_girl[i][j] - 1);
    }

    for(int i = 1; i <= 100; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= 100; j++)
            cnt += point_boy[i][j];
        res += cnt * (cnt - 1) / 2;
    }
    for(int j = 1; j <= 100; j++)
    {
        int cnt = 0;
        for(int i = 1; i <= 100; i++)
            cnt += point_boy[i][j];
        res += cnt * (cnt - 1) / 2;
    }
    for(int i = 1; i <= 100; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= 100; j++)
            cnt += point_girl[i][j];
        res += cnt * (cnt - 1) / 2;
    }
    for(int j = 1; j <= 100; j++)
    {
        int cnt = 0;
        for(int i = 1; i <= 100; i++)
            cnt += point_girl[i][j];
        res += cnt * (cnt - 1) / 2;
    }

    cout << res - minus_res;

    return 0;
}
