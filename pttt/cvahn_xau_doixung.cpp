#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - 1 - i])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
