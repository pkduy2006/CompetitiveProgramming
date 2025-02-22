#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 11;
int a[N], n, sum = 0, m;

bool check(int len)
{
    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        if(len < a[i])
            cnt += a[i] - len;
    }

    return cnt >= m;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    int l = 1, r = *max_element(a + 1, a + 1 + n);
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if(check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r;

    return 0;    
}
