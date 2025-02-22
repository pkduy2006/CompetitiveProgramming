#include <bits/stdc++.h>
using namespace std;

int n, res;
string s;

bool check(string x)
{
    for(int i = 0; i < x.size() / 2; i++)
    {
        if(x[i] != x[x.size() - i - 1])
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("XAUCONDX.inp","r",stdin);
    freopen("XAUCONDX.out","w",stdout);

    cin >> n >> s;
    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 0; j < s.size() - i + 1; j++)
        {
            string tmp = s.substr(j, i);

            if(check(tmp))
                res = max(res, (int)tmp.size());
        }
    }

    cout << res;

    return 0;
}
