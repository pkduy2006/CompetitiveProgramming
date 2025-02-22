#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 4e5 + 11, INF = 1e17 + 11;
int n, s, a[N], sum[N], res = INF;

bool check(int len)
{
    for(int i = 1; i <= n - len + 1; i++)
    {
        if(sum[i + len - 1] - sum[i - 1] >= s)
            return true;
    }

    return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if(check(mid))
        {
            res = min(mid, res);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << res;
    
    return 0;
}
