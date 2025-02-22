#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 16;
int t, n, a[N];

void Solve()
{   
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int res = 0, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] < 0)
            sum += a[i];
        else
        {
            res = min(res, sum);
            sum = 0;
        }
    }
    res = min(res, sum);

    cout << res << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DAYCONAMNN.inp","r",stdin);
    freopen("DAYCONAMNN.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();
    
    return 0;
}
