#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define setpre(n) fixed << setprecision (n)
#define sz(x) (int) x.size ()
//#define int long long
#define Task "ad"
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

signed main () {
    freopen (Task".inp", "r", stdin);
    freopen (Task".out", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);

    map <char, int> m;

    string x, y; cin >> x >> y;

    for (int i = 0; i < sz (x); i++) m[x[i]]++;
    for (int i = 0; i < sz (y); i++) m[y[i]]--;

    int res = 0;
    for (auto e : m) res += abs (e.se);

    cout << res;
    
    return 0;
}
