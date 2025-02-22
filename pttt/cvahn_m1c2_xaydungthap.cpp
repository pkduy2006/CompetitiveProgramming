#include <bits/stdc++.h>
#define int long long
using namespace std;
set<int> ans;
int a[1070], mark[1071];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        mark[a[i]]++;
        ans.insert(a[i]);
    }
    for(int i = 1; i <= n; i++)
        res = max(res, mark[a[i]]);
    cout << res << ' ' << ans.size();
    return 0;
}
