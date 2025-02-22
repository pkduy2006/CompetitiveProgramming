#include <bits/stdc++.h>
using namespace std;

string s;
int res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("nptp.inp","r",stdin);
    freopen("nptp.out","w",stdout);

    cin >> s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
            res += (1 << i);
    }

    cout << res;

    return 0;
}
