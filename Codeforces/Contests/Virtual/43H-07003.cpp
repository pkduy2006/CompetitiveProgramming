// Codeforces Round 900 (Div. 3) E. Iva & Pav
// https://codeforces.com/contest/1878/problem/E

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 7;
int ntests, n, a[N], st[4 * N], q;
 
void Build(int id, int l, int r) {
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] & st[id * 2 + 1];
}
 
int get(int id, int l, int r, int x, int y) {
    if(r < x || y < l) 
        return 1;
    if(x <= l && r <= y) 
        return st[id];
    int mid = (l + r) / 2;
    if(mid < x)
        return get(id * 2 + 1, mid + 1, r, x, y);
    else if(y < mid + 1)
        return get(id * 2, l, mid, x, y);
    else
        return get(id * 2, l, mid, x, y) & get(id * 2 + 1, mid + 1, r, x, y);
}
 
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Build(1, 1, n);
    cin >> q;
    while(q--) {
        int l, k;
        cin >> l >> k;
        int vasen = l, oikea = n;
        while(vasen <= oikea) {
            int keskella = (vasen + oikea) / 2;
            if(get(1, 1, n, l, keskella) >= k) {
                vasen = keskella + 1;
            }
            else {
                oikea = keskella - 1;
            }
        }
        if(get(1, 1, n, l, oikea) < k) {
            cout << -1 << ' ';
        }
        else {
            cout << oikea << ' ';
        }
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> ntests;
    while(ntests--) {
        solve();
    }
 
    return 0;
}