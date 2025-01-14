//2024-2025 ICPC, NERC, Southern and Volga Russian Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams) N. Fixing the Expression
//https://codeforces.com/problemset/problem/2038/N

#include <bits/stdc++.h>
using namespace std;

int ntests, cnt1, cnt2;
string s;

void solve()
{
    cin >> s;
    
    cnt1 = s[0] - '0';
    cnt2 = s[2] - '0';
    if(cnt1 < cnt2)
        cout << cnt1 << '<' << cnt2 << '\n';
    else if(cnt1 == cnt2)
        cout << cnt1 << '=' << cnt2 << '\n';
    else
        cout << cnt1 << '>' << cnt2 << '\n';
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