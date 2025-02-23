#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2016;
string dp[N];

string Add (string a, string b) 
{
    int val = 0;
    string ans;
    while (a.length() > b.length()) b = "0" + b;
    while (a.length() < b.length()) a = "0" + a;
    for (int i = (int)a.length()-1; i >= 0; i--) {
        val += (a[i] + b[i] - 96);
        ans = (char)(val % 10 + 48) + ans;
        val /= 10;
    }
    ans = (char)(val + 48) + ans;
    while (ans[0] == '0' && (int)ans.length() > 1)
        ans.erase(0,1);
    return ans;
}

main() 
{
    freopen ("TILE.inp", "r", stdin);
    freopen ("TILE.out", "w", stdout);
    ios_base::sync_with_stdio (0); 
    cin.tie (0); 
    cout.tie (0);

    int n; 
    cin >> n;

    dp[0] = "1", dp[1] = "1";
    for (int i = 2; i <= n; i++) {
        dp[i] = Add (Add (dp[i - 2], dp[i - 2]), dp[i - 1]);
    }

    cout << dp[n];
    
    return 0;
}
