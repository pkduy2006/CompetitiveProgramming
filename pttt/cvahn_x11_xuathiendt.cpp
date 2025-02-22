#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16;
int t, cnt[N];
string s;

void Solve()
{
    cin >> s;
    
    fill(cnt, cnt + N, 0);
    for(int i = 0; i < s.size(); i++)
        cnt[s[i]]++;
    
    vector<char> tmp;
    for(char i = 'a'; i <= 'z'; i++)
    {
        if(cnt[i] == 1)
            tmp.push_back(i);
    }

    if(tmp.size() == 0)
    {
        cout << -1 << '\n';

        return;
    }

    int pos = N;
    for(int i = 0; i < tmp.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            if(tmp[i] == s[j])
                pos = min(pos, j);
        }
    }

    cout << pos + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("XUATHIENDT.inp","r",stdin);
    freopen("XUATHIENDT.out","w",stdout);

    cin >> t;
    while (t--)
        Solve();

    return 0;
}
