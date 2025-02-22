#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e5 + 5;
const int oo = 1e18;
const int MOD = 1e9 + 7;

int T;

bool cmp(char a, char b) {
    return a > b;
}

signed main()
{
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        string s; cin >> s;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) sum += (s[i] - '0');
        if (sum%3 != 0) cout << -1 << '\n';
        else {
            sort(s.begin(), s.end(), cmp);
            if (s[s.length()-1] != '0') cout << -1 << '\n';
            else cout << s << '\n';
        }
    }
    return 0;
}
