#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l = 0, r = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ')')
            l++;
        else
            r++;
    }
    if(l == r)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
