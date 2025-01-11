// VNOI
// Lũy thừa
// https://oj.vnoi.info/problem/power

#include <bits/stdc++.h>
using namespace std;

int ntests, cnt = 1;
long long l, r;

bool check(int k) {
    long long vasen = 1, oikea = 1e6;
    while(vasen <= oikea) {
        long long keskella = (vasen + oikea) / 2;
        long long a = keskella;
        for(int i = 2; i <= k; i++) {
            if(a > r)
                break;
            a *= keskella;
        }
        if(l <= a && a <= r)
            return true;
        else if(a < l)
            vasen = keskella + 1;
        else
            oikea = keskella - 1;
    }
    return false;
}

void solve() {
    cin >> l >> r;
    
    cout << "Case #" << cnt << ": ";
    cnt++;
    bool tarkastus = false;
    for(int i = 40; i >= 2; i--) {
        if(check(i)) {
            cout << i << '\n';
            tarkastus = true;
            break;
        }
    }
    if(!tarkastus)
        cout << 1 << '\n';
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