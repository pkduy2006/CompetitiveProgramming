#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 13;

int a[N], b[N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dempt.inp","r",stdin);
    freopen("dempt.out","w",stdout);
    

    int n, m, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];

    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= m; i++)
    {
        int l = 1, r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;

            if(a[mid] > b[i])
                r = mid - 1;
            else if(a[mid] == b[i])
            {
                res++;
                break;
            }
            else
                l = mid + 1;
        }
    }
    cout << res;
    return 0;
}
