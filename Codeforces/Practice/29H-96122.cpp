#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int MOD = 998244353;
int ntests, a[N], n;
long long f[N][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        for(int i = 1; i <= n; i++)
            f[i][1] = f[i][2] = f[i][3] = 0;
        for(int i = 1; i <= n; i++) {
            f[i][1] = f[i - 1][1];
            f[i][2] = f[i - 1][2];
            f[i][3] = f[i - 1][3];
            if(a[i] == 1)
                f[i][1]++;
            else if(a[i] == 2) {
                f[i][2] += f[i - 1][2];
                f[i][2] %= MOD;
                f[i][2] += f[i - 1][1];
                f[i][2] %= MOD;
            }
            else {
                f[i][3] += f[i - 1][2];
                f[i][3] %= MOD;
            }
        }
        cout << f[n][3] << '\n';
    }

    return 0;
}