//Codeforces Round 981 (Div. 3) A. Sakurako and Kosuke
//https://codeforces.com/problemset/problem/2033/A

#include <bits/stdc++.h>
using namespace std;

int ntests, n;

void solve()
{
    cin >> n;

    if(n % 2 == 1)
        cout << "Kosuke" << '\n';
    else
        cout << "Sakurako" << '\n';
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