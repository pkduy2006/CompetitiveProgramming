#include <bits/stdc++.h>
#define int long long
using namespace std;

string s1, s2;

void Read()
{
    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++)
    {
        if('A' <= s1[i] && s1[i] <= 'Z')
            s1[i]+=32;
    }

    for(int i = 0; i < s2.size(); i++)
    {
        if('A' <= s2[i] && s2[i] <= 'Z')
            s2[i]+=32;
    }
}

void Solve()
{
    int cnt = 1;
    string res = "";

    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == s1[i + 1])
            cnt++;
        else
        {
            if(cnt > 2)
            {
                string total = to_string(cnt);
                res += total;
                res += s1[i];
                cnt = 1;
            }
            else
            {
                for(int j = 1; j <= cnt; j++)
                    res += s1[i];
                cnt = 1;
            }
        }
    }

    for(int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << '\n';

    string sum = "", ans = "";
    for(int i = 0; i < s2.size(); i++)
    {
        if('0' <= s2[i] && s2[i] <= '9')
            sum += s2[i];
        else
        {
            if(sum != "")
            {
                int n = stoi(sum);
                for(int j = 1; j <= n; j++)
                    cout << s2[i];
            }
            else
                cout << s2[i];
            sum = "";
        }
    }
}

main()
{
    freopen("NENXAU.inp","r",stdin);
    freopen("NENXAU.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
