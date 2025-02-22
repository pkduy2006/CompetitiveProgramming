#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1031][1032];
int ans[1033];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= m; i++)
            ans[j] = max(ans[j], a[i][j]);
    }
    int res = *min_element(ans + 1, ans + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] == res)
            cout << i << ' ';
    }
    return 0;
}
