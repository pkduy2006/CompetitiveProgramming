#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int b[3], dp[N], res = 0, n;
struct stone
{
    int x, y, h;
} a[N];

bool cmp(stone me, stone her)
{
    return me.x * me.y > her.x * her.y;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[0] >> b[1] >> b[2];
        sort(b, b + 3);
        a[i].x = b[1];
        a[i].y = b[2];
        a[i].h = b[0];
    }
}

void Solve()
{
    sort(a + 1, a + 1 + n, cmp);
    dp[1] = a[1].h;

    //for(int i = 1; i <= n; i++)
        //cout << a[i].x << ' ' << a[i].y << ' ' << a[i].h << '\n';

    for(int i = 2; i <= n; i++)
    {
        dp[i] = a[i].h;
        for(int j = 1; j <= i - 1; j++)
        {
            if(((a[i].y <= a[j].y && a[i].x <= a[j].x) || (a[i].y < a[j].x && a[i].x < a[j].y)) && dp[i] < dp[j] + a[i].h)
                dp[i] = dp[j] + a[i].h;
        }

        res = max(res, dp[i]);
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("tower.inp","r",stdin);
    freopen("tower.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();


}
