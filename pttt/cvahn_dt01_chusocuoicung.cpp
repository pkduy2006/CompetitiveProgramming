#include <bits/stdc++.h>
#define int long long 
using namespace std;

int m, n, k, MOD = 1;

int power(int x, int y)
{
    if(y == 0)
        return 1;
    
    int tmp = power(x, y / 2);

    if(y % 2 == 0)
        return (tmp * tmp) % MOD;
    return (((tmp * tmp) % MOD) * x) % MOD;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("chuso.inp","r",stdin);
    freopen("chuso.out","w",stdout);

    cin >> m >> n >> k;

    for(int i = 1; i <= k; i++)
        MOD *= 10;

    int res = power(m, n);
    string res_ver2 = to_string(res);

    if(res_ver2.size() < k)
    {
        for(int i = 1; i <= k - res_ver2.size(); i++)
            cout << 0;
        cout << res_ver2;
    }
    else
        cout << res_ver2;
    
    return 0;
}
