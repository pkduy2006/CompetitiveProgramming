#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 11, INF = 1e17 + 11;
int n, a[N], k, sum = 0, res = INF;

int calculate(int sz)
{
    int total = 0, cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        //cout << total << '\n';

        if(total + a[i] <= sz)
            total += a[i];
        else
        {
            total = a[i];
            cnt++;
        }
    }

    return cnt;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("Novel.inp","r",stdin);
    freopen("Novel.out","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int l = *max_element(a + 1, a + 1 + n), r = sum;
    while(l <= r)
    {
        int mid = (l + r) / 2;

        if(calculate(mid) <= k)
        {
            r = mid - 1;
            res = min(res, mid);
        }
        else
            l = mid + 1;
    }

    cout << res;

    return 0;
}
