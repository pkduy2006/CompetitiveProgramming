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
        vector<int> a(n + 1), res;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        int mark = a[n];
        res.push_back(mark);
        for(int i = n - 1; i >= 1; i--)
        {
            if(a[i] > mark)
            {
                res.push_back(a[i]);
                mark = a[i];
            }
        }
        for(int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}
