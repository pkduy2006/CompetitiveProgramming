#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
string s, answer;
int res = INF;

void update(string l, string r)
{
    if(l.size() < r.size())
        swap(l, r);
    reverse(l.begin(), l.end());

    for(int i = 0; i < r.size(); i++)
    {
        if(l[i] != r[i])
            return;
    }

    reverse(l.begin(), l.end());
    if(res > l.size() - r.size())
    {
        if(r.size() == 0)
        {
            res = l.size() - r.size() - 1;
            answer = l;
            reverse(l.begin(), l.end());
            for(int i = 1; i < l.size(); i++)
                answer += l[i];
        }
        else
        {
            res = l.size() - r.size();
            answer = l;
            reverse(l.begin(), l.end());
            answer += l;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);

    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        string l = "", r = "";
        for(int j = 0; j <= i; j++)
            l += s[j];
        for(int j = i + 1; j < s.size(); j++)
            r += s[j];

        update(l, r);
    }

    cout << res << '\n' << answer;

    return 0;
}
