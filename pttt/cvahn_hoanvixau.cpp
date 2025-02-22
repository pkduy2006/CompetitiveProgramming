#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;

void Read()
{
    cin >> s;
}

void Solve()
{
    sort(s.begin(), s.end());
    cout << s << '\n';
    while(next_permutation(s.begin(), s.end()))
        cout << s << '\n';
}

main()
{
    freopen("hvxau.inp","r",stdin);
    freopen("hvxau.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
