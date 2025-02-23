#include <bits/stdc++.h>
#define int long long
#define TASK "Thichay"

using namespace std;
const int NM = 3e5+7;
const int INF = 1e9+7;

int n,a[NM],d;


main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(TASK".inp","r",stdin); freopen(TASK".out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1,a+1+n);

    int mx = -1;

    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i] + n  - i + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] + n >= mx) {
            cout << n - i + 1;
            break;
        }
    }

    return 0;
}
