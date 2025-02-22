#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int res = 0;
    getline(cin, s);
    s = ' ' + s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' && s[i + 1] != ' ')
            res++;
    }
    cout << res;
    return 0;
}
