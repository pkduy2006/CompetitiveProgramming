// Codeforces Round 1003 (Div. 4) A. Skibidus and Amog'u
// https://codeforces.com/contest/2065/problem/A

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

        string res = "";
        for(int i = 0; i < s.size() - 2; i++)
            res += s[i];
        res += 'i';
        cout << res << '\n';
    }
    
    return 0;
}