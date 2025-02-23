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

void bi_search(int i, int j, int l, int r)
{
    int pos = j;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[i] + a[j] > a[mid])
        {
            pos = mid;
            l = mid + 1;
        }
        else r = mid - 1;

    }
    ans += pos - j;
}


main()
{
    freopen("BSTG.inp", "r", stdin);
    freopen("BSTG.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            bi_search(i, j, j + 1, n);

    cout << ans;
}
