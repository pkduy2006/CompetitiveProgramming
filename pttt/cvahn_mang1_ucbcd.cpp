#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ucln=0;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int t=*max_element(a.begin(), a.end());
    for(int i=1; i<=t; i++)
    {
        bool check=true;
        for(int j=1; j<=n; j++)
        {
            if(a[j]%i!=0)
                check=false;
        }
        if(check==true)
            ucln=i;
    }
    int bcnn=(a[1]*a[2])/__gcd(a[1], a[2]);
    for(int i=3; i<=n; i++)
    {
        bcnn=(bcnn*a[i])/__gcd(bcnn, a[i]);
    }
    cout << ucln << ' ' << bcnn;
    return 0;
}
