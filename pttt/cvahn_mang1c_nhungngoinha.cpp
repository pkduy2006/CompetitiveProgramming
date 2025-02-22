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
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1; i<=n; i++)
            cin >> a[i];
        int maxheight=a[1];
        int cnt=1;
        if(maxheight==0)
            cnt=0;
        for(int i=2; i<=n; i++)
        {
            if(a[i]>=maxheight)
            {
                maxheight=a[i];
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
