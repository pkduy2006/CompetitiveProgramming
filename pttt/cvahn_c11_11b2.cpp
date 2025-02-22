#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int N = 1e5 + 7;
int a[N], dp[N], sum[N];

signed main () {
    freopen ("Bai2.inp", "r", stdin);
    freopen ("Bai2.out", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i];
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = 0;

        for (int j = i - 1; j >= 1; j--)
            if (a[i] > a[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j];
                tmp = j;
                if (dp[i] == dp[j] && sum[i] < sum[j]) {
                    sum[i] = sum[j];
                    tmp = j;
                }
            }

        dp[i]++;
        sum[i] = sum[tmp] + a[i];
    }

    int pos = 1;
    for (int i = 2; i <= n; i++)
        if (dp[i] > dp[pos]) pos = i;
        else if (dp[i] == dp[pos] && sum[i] > sum[pos]) pos = i;
    cout << dp[pos] << ' ' << sum[pos];

    return 0;
}
