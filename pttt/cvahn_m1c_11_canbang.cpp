#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 16;
int t, n, a[N], sum_left[N], sum_right[N];

void Solve()
{
    int pos = -1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sum_left[0] = sum_right[n + 1] = 0ll;
    for(int i = 1; i <= n; i++)
        sum_left[i] = sum_left[i - 1] + a[i];
    for(int i = n; i >= 1; i--)
        sum_right[i] = sum_right[i + 1] + a[i];
    
    for(int i = 1; i <= n; i++)
    {
        if(sum_left[i] == sum_right[i])
        {   
            pos = i;
            break;
        }
    }

    cout << pos << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // freopen("input.txt","r",stdin);
    freopen("CANBANG.inp","r",stdin);
    freopen("CANBANG.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();
    
    return 0;
}
