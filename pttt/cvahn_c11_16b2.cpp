#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x, y;

bool check(int times)
{
    int cnt = 0;
    cnt++;
    cnt += (times - min(x, y)) / x + (times - min(x, y)) / y;

    return cnt >= n;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU2.inp","r",stdin);
    freopen("CAU2.out","w",stdout);

    cin >> n >> x >> y;

    if(x > y)
        swap(x, y);
    int l = 0, r = max(n * x, n * y);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    cout << l;

    return 0;
}
