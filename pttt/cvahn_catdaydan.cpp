#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e4 + 25;
int n, k, a[N], s = 0;

int check(int m)
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += a[i] / m;
        if(cnt == k)
            break;
    }

    return cnt;
}

void Read()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
}

void Solve()
{
     int r = s / k, l = 1, res = 0;

     while(l <= r)
     {
         int mid = (l + r) / 2;
         if(check(mid) == k)
         {
             res = max(res, mid);
             l = mid + 1;
         }
         else if(check(mid) > k)
            l = mid + 1;
         else
            r = mid - 1;
     }

     cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("catday.inp","r",stdin);
    freopen("catday.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
