#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 16;
int n, a[N], p[N], cur, cur_prize, res;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MUAXANG.inp","r",stdin);
    freopen("MUAXANG.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    cur = a[1];
    cur_prize = p[1];
    for(int i = 2; i <= n; i++)
    {
        if(cur_prize > p[i])
        {
            res += cur * cur_prize;
            cur = a[i];
            cur_prize = p[i];
        }
        else
            cur += a[i];
    }
    res += cur * cur_prize;

    cout << res;

    return 0;
}
