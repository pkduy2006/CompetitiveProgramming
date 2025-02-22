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
        vector<int> a(n + 1), sum(n + 1);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        bool check = false;
        for(int i = 1; i <= n; i++)
        {
            if(sum[i - 1] == sum[n] - sum[i])
            {
                cout << i << '\n';
                check = true;
            }
        }
        if(check == false)
            cout << -1 << '\n';
    }
    return 0;
}
