#include <bits/stdc++.h>
using namespace std;

string n;
int res = -1, answer;

bool check(int x)
{
    if(x < 2)
        return false;
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
            return false;
    }

    return true;
}

void ss(int idx, string tmp)
{
    if(idx == n.size())
    {
        int answer = 0, factor = 1;
        for(int i = tmp.size() - 1; i >= 0; i--)
        {
            answer += (tmp[i] - '0') * factor;
            factor *= 10;
        }

        if(check(answer))
            res = max(res, answer);
        //cout << tmp << ' ' << answer << '\n';
        return;
    }

    ss(idx + 1, tmp + n[idx]);
    ss(idx + 1, tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);

    cin >> n;

    ss(0, "");

    cout << res;

    return 0;
}
