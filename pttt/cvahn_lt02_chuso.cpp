#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n, k, res = 1, MOD = 1;
    cin >> m >> n >> k;
    for(int i = 1; i <= k; i++)
        MOD*=10;
    for(int i = 1; i <= n; i++)
    {
        res*=m;
        res%=MOD;
    }
    string ans = to_string(res);
    int t = ans.size();
    while(t < k)
    {
        cout << 0;
        t++;
    }
    cout << res;
    return 0;
}
