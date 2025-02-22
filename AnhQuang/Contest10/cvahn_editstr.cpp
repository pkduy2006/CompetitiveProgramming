#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 16;
string s, x;
int f[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("EDITSTR.INP","r",stdin);
    freopen("EDITSTR.OUT","w",stdout);

    cin >> s >> x;
    
    s = ' ' + s;
    x = ' ' + x;
    for(int i = 1; i < x.size(); i++)
        f[0][i] = i;
    for(int i = 1; i < s.size(); i++)
        f[i][0] = i;
    for(int i = 1; i < s.size(); i++)
    {
        for(int j = 1; j < x.size(); j++)
        {
            if(s[i] == x[j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min({f[i - 1][j - 1] + 1, f[i - 1][j] + 1, f[i][j - 1] + 1});
        }
    }

    cout << f[s.size() - 1][x.size() - 1];
    return 0;
}
