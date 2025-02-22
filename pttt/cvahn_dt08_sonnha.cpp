#include <bits/stdc++.h>
#define int long long
using namespace std;

char m[] = {'X', 'D', 'V', 'T'};

int n;
string s;

void Read()
{
    cin >> n >> s;
}

void Solve()
{
    int res = 0;
    for(int i = 1; i < n - 1; i++)
    {
        if(s[i + 1] == s[i] && s[i] == s[i - 1])
        {
            res++;
            for(int j = 0; j < 4; j++)
            {
                if(s[i + 1] != m[j] && s[i - 1] != m[j])
                    s[i] = m[j];
            }
        }
    }

    for(int i = 1; i < n - 1; i++)
    {
        if(s[i + 1] == s[i] || s[i] == s[i - 1])
        {
            res++;
            for(int j = 0; j < 4; j++)
            {
                if(s[i + 1] != m[j] && s[i - 1] != m[j])
                    s[i] = m[j];
            }
        }
    }

    cout << res;
}

main()
{
    freopen("house.inp","r",stdin);
    freopen("house.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
