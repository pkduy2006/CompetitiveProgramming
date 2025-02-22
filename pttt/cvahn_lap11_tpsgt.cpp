#include <bits/stdc++.h>
using namespace std;

long double res, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TONGPSGT.inp","r",stdin);
    freopen("TONGPSGT.out","w",stdout);

    cin >> n;
    for(long double i = 1; i <= n; i++)
    {
        long double tmp = 1;
        for(long double j = 2; j <= i; j++)
            tmp /= j;
        res += tmp;
    }

    cout << fixed << setprecision(10) << res;

    return 0;
}
