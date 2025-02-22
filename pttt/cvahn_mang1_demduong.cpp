#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10116];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, sum=0, cnt=0;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i]>0)
        {
            sum+=a[i];
            cnt++;
        }
    }
    cout << cnt << ' ' << sum;
    return 0;
}
