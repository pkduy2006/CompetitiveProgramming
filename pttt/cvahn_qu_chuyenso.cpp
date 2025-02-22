#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int t = k % n;
    for(int i = t + 1; i <= n; i++)
        cout << a[i] << ' ';
    for(int i = 1; i <= t; i++)
        cout << a[i] << ' ';
    return 0;
}
