#include <bits/stdc++.h>
#define int long long
using namespace std;
set<char> res;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if('A' <= s[i] && s[i] <= 'Z')
            s[i]+=32;
        res.insert(s[i]);
    }
    cout << res.size();
    return 0;
}
