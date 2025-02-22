#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int n, k, tmp, res, sum, a[N];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
            cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
                tmp = lower_bound(a + j + 1, a + n, a[i] + a[j]) - a;
                res = res + (tmp - j - 1);
        }
    }
    cout << res;
    return 0;
}
