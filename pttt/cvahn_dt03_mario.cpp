#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define setpre (n) fixed << setprecision (n)
#define sz (x) (int) x.size ()
#define int long long
#define Task "Mario"
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int oo = 1e9;
const int N = 3e5 + 7;
int t[N];
string dp[N];

string Add (string a, string b) {
    int val = 0;
    string ans;
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    for (int i = (int)a.length()-1; i >= 0; i--) {
        val += (a[i] + b[i] - 96);
        ans = (char)(val % 10 + 48) + ans;
        val /= 10;
    }
    ans = (char)(val + 48) + ans;
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    return ans;
}

signed main () {
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> t[i];

    fill (dp, dp + n + 2, "0");

    dp[0] = "1";
    if (t[1] != 2) dp[1] = "1";
    if (t[2] == 0) dp[2] = Add (dp[0], dp[1]);
    else if (t[2] == 1) dp[2] = dp[1];

    for (int i = 3; i <= n + 1; i++) {
        if (t[i] == 0) {
            dp[i] = Add (dp[i - 2], dp[i - 1]);
            if (t[i - 3] == 0) dp[i] = Add (dp[i], dp[i - 3]);
        }

        else if (t[i] == 1) dp[i] = dp[i - 1];
    }

    cout << dp[n + 1];
    
    return 0;
}
