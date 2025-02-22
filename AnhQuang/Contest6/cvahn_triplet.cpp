#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 16;
int a[N], b[N];
long long res, m, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TRIPLET.inp","r",stdin);
    freopen("TRIPLET.out","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    sort(a + 1, a + 1 + m);
    for(int i = 1; i <= n; i++)
    {
        long long l = lower_bound(a + 1, a + 1 + m, b[i]) - a - 1;
        long long r = upper_bound(a + 1, a + 1 + m, b[i]) - a;

        res += (m - r + 1) * l;
    }

    cout << res;

    return 0;
}
