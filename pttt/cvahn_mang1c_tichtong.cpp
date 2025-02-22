#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while(ntest--)
    {
        int n, LeftSum=0, RightSum=0;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];
        for(int i=1; i<=n/2; i++)
            LeftSum+=a[i];
        for(int i=n/2+1; i<=n; i++)
            RightSum+=a[i];
        cout << RightSum*LeftSum << '\n';
    }
    return 0;
}
