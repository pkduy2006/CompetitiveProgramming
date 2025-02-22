#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 31;
int n, a[N][N], res = 0, ans = 0;
bool check[N];

void choose(int m)
{
    for(int i = 1; i <= n; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            ans += a[m][i];

            if(m == n)
                res = max(res, ans);
            else
                choose(m + 1);

            ans -= a[m][i];
            check[i] = false;
        }
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
    choose(1);

    cout << res;
}

main()
{
    freopen("Chonso.inp","r",stdin);
    freopen("Chonso.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
