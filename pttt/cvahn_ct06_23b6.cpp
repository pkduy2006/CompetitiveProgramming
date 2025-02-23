#include <bits/stdc++.h>
#define int long long
#define TASK "novel"

using namespace std;
const int NM = 1e5+7;
const int INF = 1e9+7;

int n,k,a[NM],l,r,res;

bool check(int mid) {
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum > mid) {
            sum = a[i];
            cnt++;
        }
        else if (sum == mid) {
            sum = 0;
            cnt++;
        }
    }

    if (sum > 0) cnt++;

    if (cnt <= k ) return true;
    else return false;

}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen(TASK".inp","r",stdin); freopen(TASK".out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }

    while (l <= r) {
        int mid = (l + r) / 2;
        //cout << mid << " " << check(mid) << '\n';
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}
