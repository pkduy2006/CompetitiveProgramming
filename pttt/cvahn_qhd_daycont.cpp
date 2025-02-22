#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;
    cin >> n;
    vector<int> a(n + 1), ans, f(n + 1, 1), lastRes;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }

    int idx = n;
    cout << res << '\n';
    while(res >= 1)
    {
        for(int i = idx; i >= 1; i--)
        {
            if(res == f[i])
            {
                ans.push_back(a[i]);
                idx = i - 1;
                break;
            }
        }
        res--;
    }
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}
