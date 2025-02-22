#include <bits/stdc++.h>
using namespace std;

int res;
string s, a;

int convert(string tmp)
{
    int answer = 0, factor = 1;
    for(int i = tmp.size() - 1; i >= 0; i--)
    {
        answer += factor * (tmp[i] - '0');
        factor *= 10;
    } 

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("TINHTONG.inp","r",stdin);
    freopen("TINHTONG.out","w",stdout);

    getline(cin, s);

    for(int i = 0; i < s.size(); i++)
    {
        if('0' <= s[i] && s[i] <= '9')
            a += s[i];
        else
        {
            res += convert(a);
            a = "";
        }
    }
    res += convert(a);

    cout << res;

    return 0;
}
