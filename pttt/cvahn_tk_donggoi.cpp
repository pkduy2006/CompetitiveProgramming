#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 +7;
int n, m, a[N], k, mid, maxa, tong, l ,r;

bool datduoc(int mid)
{
    int d = 0, dem = 1;
    for(int i = 1; i <= n; i++)
    {
        if(d + a[i] <= mid) d+= a[i];
        else
        {
            dem++; d = a[i];
        }
    }
    if(dem <= k) return 1;
    else return 0;
}

main()
{
    freopen("zxy.inp","r",stdin);
    freopen("zxy.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong += a[i];
        maxa = max(maxa,a[i]);
    }
    l = maxa; r = tong;
    while(l <= r)
    {
        mid = (l + r)/2;
        if(datduoc(mid))
        {
            m = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << m;
    return 0;
}
