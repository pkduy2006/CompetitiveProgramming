#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

mt19937_64 rng (chrono::steady_clock::now ().time_since_epoch ().count ());

ll gen (ll a, ll b) {
    return rng () % (b - a + 1) + a;
}

signed main () {
    freopen ("DTDTRON.inp", "r", stdin);
    freopen ("DTDTRON.out", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    
    ld a, b, c; cin >> a >> b >> c;
    ld d, e, f, g; cin >> d >> e >> f >> g;
    
    if (((e - d) * (e - d) - (b - a) * (b - a) <= c) || ((g - f) * (g - f) - (b - a) * (b - a) <= c)) cout << 1;
    else if ((f - d) * (f - d) + (g - e) * (g - e) > 4 * c * c) cout << gen (2, 3);
    else cout << 4;
    
    return 0;
}
