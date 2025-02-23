#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4 + 25, INF = 1e17 + 7;
int n, k, r = 0, a[N];

int check(int m)
{
    int cnt = 1, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(sum + a[i] > m)
        {
            sum = 0;
            cnt++;
        }

        sum += a[i];
    }

    return cnt;
}

void Read()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r += a[i];
    }
}

void Solve()
{
    int l = 1, res = INF;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid) <= k)
        {
            res = min(res, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("zxy.inp","r",stdin);
    freopen("zxy.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
