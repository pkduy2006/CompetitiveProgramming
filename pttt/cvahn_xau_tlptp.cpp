#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("16210.inp","r",stdin);
    //freopen("16210.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int cnt = 1, res = 0;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if('0' <= s[i] && s[i] <= '9')
            res += (s[i] - '0') * cnt;
        else if(s[i] == 'A')
            res += 10 * cnt;
        else if(s[i] == 'B')
            res += 11 * cnt;
        else if(s[i] == 'C')
            res += 12 * cnt;
        else if(s[i] == 'D')
            res += 13 * cnt;
        else if(s[i] == 'E')
            res += 14 * cnt;
        else if(s[i] == 'F')
            res += 15 * cnt;
        cnt *= 16;
    }
    cout << res;
    return 0;
}
