#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
const int INF = 1e9 + 7;
int n, res = INF;
string s[N], ss;

bool check()
{
    for(int i = 0; i < ss.size(); i++)
    {
        bool review = false;
        for(int j = 1; j <= n; j++)
        {
            for(int k = 0; k <= s[j].size(); k++)
            {
                if(ss[i] == s[j][k])
                    review = true;
            }
        }

        if(!review)
            return false;
    }

    return true;
}

int cnt(string x)
{
    int answer = 0;
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] != ss[i])
            answer++;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BIENDOIXAU.inp","r",stdin);
    freopen("BIENDOIXAU.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    cin >> ss;

    if(!check())
    {
        cout << -1;
        return 0;
    }

    for(int i = 1; i <= n; i++)
        res = min(res, cnt(s[i]));
    
    cout << res;

    return 0;
}
