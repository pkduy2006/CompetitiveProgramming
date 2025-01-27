#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;
int ntests, a[N], l, r, n, la[N], ra[N];
long long suml, sumr;

void solve() {
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        la[i] = ra[i] = a[i];
    }

    suml = sumr = 0;
    sort(la + 1, la + 1 + r);
    sort(ra + l, ra + 1 + n);
    /*for(int i = 1; i <= n; i++)
        cout << ra[i] << ' ';
    cout << '\n';*/
    for(int i = 1; i <= r - l + 1; i++) 
        suml += la[i];
    for(int i = l; i <= r; i++)
        sumr += ra[i];
    cout << min(suml, sumr) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();

    return 0;
}