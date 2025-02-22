#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
set<string> a;

bool check(string s)
{
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == 'B' && s[i + 1] == 'B')
            return false;
    }

    return true;
}

void Read()
{
    cin >> n;
}

void Solve()
{
    string res = "";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            res += 'A';
        for(int j = i + 1; j <= n; j++)
            res += 'B';

        if(check(res))
            a.insert(res);
        while(next_permutation(res.begin(), res.end()))
        {
            if(check(res))
                a.insert(res);
        }
        res = "";
    }

    for(auto it = a.begin(); it != a.end(); it++)
        cout << *it << '\n';
}

main()
{
    freopen("Taoxau.inp","r",stdin);
    freopen("Taoxau.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
