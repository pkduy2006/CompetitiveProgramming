#include <bits/stdc++.h>
#define ont long long
using namespace std;

string s, x;
int res = 0;

void Read()
{
    cin >> s >> x;
}

void Solve()
{
    int i = 0;

    while(i < s.size())
    {
        string m = s.substr(i, x.size());

        if(m == x)
        {
            res++;
            i += x.size();
        }
        else
            i++;
    }

    cout << res;
}

main()
{
    freopen("ARN.inp","r",stdin);
    freopen("ARN.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
