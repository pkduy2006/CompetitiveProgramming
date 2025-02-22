#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 16;
int k, cnt[N];
string s, res;

bool check()
{
    for(char i = 'a'; i <= 'z'; i++)
    {
        if(cnt[i] % k != 0)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("kstring.inp","r",stdin);
    freopen("kstring.out","w",stdout);
    
    cin >> k >> s;
    
    for(int i = 0; i < s.size(); i++)
        cnt[s[i]]++;

    if(check())
    {
        cout << -1;

        return 0;
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        int tmp = cnt[i] / k;
        for(int j = 1; j <= tmp; j++)
            res += i;
    }
    
    for(int i = 1; i <= k; i++)
        cout << res;

    return 0;
}
