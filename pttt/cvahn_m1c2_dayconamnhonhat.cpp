#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while(ntest--)
    {
        int n, total = 0, res = 0;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] < 0)
                total += a[i];
            else
            {
                res = min(res, total);
                total = 0;
            }
        }
        res = min(res, total);
        cout << res << '\n';
    }
    return 0;
}
