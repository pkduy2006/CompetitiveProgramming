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
        int n, res=0;
        cin >> n;
        vector<int> a(n+1);
        for(int i=0; i<n; i++)
                cin >> a[i];
        for(int i=0; i<=n-2; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(i*a[i]>j*a[j])
                    res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
