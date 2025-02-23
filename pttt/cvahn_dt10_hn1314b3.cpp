#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define setpre(n) fixed << setprecision (n)
#define sz(x) (int) x.size ()
//#define int long long
#define Task "Bai3"
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int N = 1e5 + 7, oo = 1e9 + 9;
int n, k, len[N];

bool Solve (int val) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += len[i] / val;

    if (cnt >= k) return true;
    else return false;
}

int BinarySearch (int left, int right) {
    int res = -1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (Solve (mid)) {
            res = mid;
            left = mid + 1;
        } else right = mid - 1;
    }

    return res;
}

signed main () {
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);

    cin >> n >> k;

    int max_ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        len[i] = b - a;
        max_ans = max (max_ans, len[i]);
    }

    cout << BinarySearch (1, max_ans);
    
    return 0;
}
