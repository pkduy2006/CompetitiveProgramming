//Educational Codeforces Round 170 (Rated for Div. 2) A. Two Screens
//https://codeforces.com/problemset/problem/2025/A
//11/50

#include <bits/stdc++.h>
using namespace std;

int ntests;
string s, t, a;

void solve()
{
    a = "";

    cin >> s >> t;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == t[i])
            a += s[i];
        else
            break;
    }

    cout << min(s.size() + t.size() - a.size() + 1, s.size() + t.size()) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}