#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 6;

int a[N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, total = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    sort(a + 1, a + 1 + n);

    for(int i = n / k; i >= 1; i--)
        total -= a[n - i * k + 1];

    cout << total;
    return 0;
}
