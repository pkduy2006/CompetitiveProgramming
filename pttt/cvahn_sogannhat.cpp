#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;

void Read()
{
    cin >> s;
}

void Solve()
{
    string m = s;
    while(next_permutation(s.begin(), s.end()))
    {
        if(s > m)
        {
            cout << s;
            return;
        }
    }

    cout << 0;
}

main()
{
    freopen("Sogannhat.inp","r",stdin);
    freopen("Sogannhat.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
