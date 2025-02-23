#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
string s;
set<char> c;
int res;

bool check(int l, int r)
{
    string x = "";
    for(int i = l; i <= r; i++)
        x += s[i];
    string y = x;
    reverse(x.begin(), x.end());

    //cout << l << ' ' << r << ' ' << x << ' ' << y << '\n';
    return x == y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TKXAU.inp","r",stdin);
    freopen("TKXAU.out","w",stdout);

    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
        c.insert(s[i]);
   
    for(int i = 0; i < s.size() - 1; i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            if(check(i, j))
            {
                //cout << i << ' ' << j << '\n';
                res = max(res, j - i + 1);
            }
        }
    }

    cout << c.size() << '\n' << res;

    return 0;
}
