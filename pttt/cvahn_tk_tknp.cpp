#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("tknp.inp","r",stdin);
    freopen("tknp.out","w",stdout);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(a[mid] > x)
            r = mid - 1;
        else if(a[mid] == x)
        {
            cout << mid + 1;
            return 0;
        }
        else
            l = mid + 1;
    }
    cout << 0;
    return 0;
}
