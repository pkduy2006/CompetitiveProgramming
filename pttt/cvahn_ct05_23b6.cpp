#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N], ans;

bool check(int m)
{
    int pos = 1;
    for (int i = pos + 1; i <= n; i++)
    {
        if (a[pos] < a[i] && a[i] - a[pos] <= m) 
            pos = i;
    }
    
    if (pos == n || a[pos] > a[n]) 
        return true;
    return false;
}


main()
{
    freopen("NHIETDO.inp", "r", stdin);
    freopen("NHIETDO.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1, r = a[n] - a[1];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else 
        l = mid+1;
    }
    
    cout << ans;

    return 0;
}
