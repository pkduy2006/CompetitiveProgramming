#include <bits/stdc++.h>
#define int long long
using namespace std;

int l, r;

bool check(int m)
{
    string k = to_string(m);
    for(int i = 0; i < k.size() - 1; i++)
    {
        for(int j = i + 1; j < k.size(); j++)
        {
            if(k[i] == k[j])
                return false;
        }
    }

    return true;
}

void Read()
{
    cin >> l >> r;
}

void Solve()
{
    for(int i = l; i <= r; i++)
    {
        if(check(i))
        {
            cout << i;
            return;
        }
    }

    cout << -1;
}

main()
{
    freopen("Chusophanbiet.inp","r",stdin);
    freopen("Chusophanbiet.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
