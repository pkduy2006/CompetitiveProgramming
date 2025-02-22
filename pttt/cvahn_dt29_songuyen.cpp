#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e17 + 11;
int a1, a2, b1, b2, res = INF;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Songuyen.inp","r",stdin);
    freopen("Songuyen.out","w",stdout);

    cin >> a1 >> b1 >> a2 >> b2;

    for(int i = 0; i <= 10000000; i++)
    {
        if(a2 == 0)
        {
            cout << 0;

            return 0;
        }

        int x2 = ((a1 * i + b1) - b2) / a2;

        if(a2 * x2 + b2 == a1 * i + b1)
            res = min(res, i + x2);
    }

    cout << res;

    return 0;
}
