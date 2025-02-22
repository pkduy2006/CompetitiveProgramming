#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100067];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << max(a[n] * a[n - 1] * a[n - 2], a[1] * a[2] * a[n]);
    return 0;
}
