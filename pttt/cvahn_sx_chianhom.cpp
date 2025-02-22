#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, h, res = 1;
    cin >> n >> h;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int dif = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        dif -= a[i];
        if(dif > h)
        {
            dif = a[i];
            res++;
        }
        else
            dif += a[i];
    }

    cout << res;
    return 0;
}
