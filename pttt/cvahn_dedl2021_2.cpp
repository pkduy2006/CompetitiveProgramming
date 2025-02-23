#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16;
const int INF = 1e9 + 7;
int t, mark[N], res = INF;
string s;

void ss()
{
    cin >> s;
    fill(mark, mark + N, 0);
    for(int i = 0; i < s.size(); i++)
        mark[s[i]]++;
    res = INF;

    for(char i = 'a'; i <= 'z'; i++)
    {
        if(mark[i] == 1)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(s[j] == i)
                    res = min(res, j);
            }
        }
    }

    if(res == INF)
        cout << -1 << '\n';
    else
        cout << res + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
        ss();

    return 0;
}
