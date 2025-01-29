// cses 
// Bit Strings 
// https://cses.fi/problemset/task/1617/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n;

long long power(long long x, long long y) {
    if(y == 0)
        return 1;
    
    long long tmp = power(x, y / 2);
    if(y % 2 == 0)
        return tmp * tmp % MOD;
    return (((tmp * tmp) % MOD) * x) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << power(2, n);

    return 0;
}
