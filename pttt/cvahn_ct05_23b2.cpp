#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

typedef long long ll;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int oo = 1e9;
const int MOD = 1e9;

int ans, kq, x, a[N], n, k;

bool check(int mid)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (a[i] / mid);

    if (sum >= k) return 1;
    return 0;
}

void bi_search(int l, int r)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
}


main()
{
    freopen("CATDAY.inp", "r", stdin);
    freopen("CATDAY.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }

    bi_search(0, tong / k);
}
