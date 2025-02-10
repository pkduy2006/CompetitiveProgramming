// Codeforces Round 1003 (Div. 4) B. Skibidus and Ohio
// https://codeforces.com/contest/2065/problem/B 

#include <bits/stdc++.h>
using namespace std;

int ntests;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> s;

        int res = s.size();
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1]) {
                res = 1;
                break;
            }
        }
        cout << res << '\n';
    }

    return 0;
}