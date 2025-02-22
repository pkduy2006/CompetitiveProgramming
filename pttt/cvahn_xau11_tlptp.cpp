#include <bits/stdc++.h>
using namespace std;

long long res, factor = 1;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TLPTP.inp","r",stdin);
    freopen("TLPTP.out","w",stdout);

    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if('0' <= s[i] && s[i] <= '9')
            res += factor * (s[i] - '0');
        else if(s[i] == 'A')
            res += factor * 10;
        else if(s[i] == 'B')
            res += factor * 11;
        else if(s[i] == 'C')
            res += factor * 12;
        else if(s[i] == 'D')
            res += factor * 13;
        else if(s[i] == 'E')
            res += factor * 14;
        else
            res += factor * 15;
        factor *= 16;
    }

    cout << res;

    return 0;
}
