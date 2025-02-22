#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 16;
int n;
long long maxLeft[N], maxRight[N], a[N], res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("RAINWATER.inp","r",stdin);
    freopen("RAINWATER.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
        maxLeft[i] = max(maxLeft[i - 1], a[i]);
    for(int i = n; i >= 1; i--)
        maxRight[i] = max(maxRight[i + 1], a[i]);

    for(int i = 1; i <= n; i++)
        res += max(0ll, min(maxLeft[i], maxRight[i]) - a[i]);

    cout << res;

    return 0;
}
