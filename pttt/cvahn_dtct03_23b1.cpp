#include <bits/stdc++.h>
using namespace std;

int x, res = -1;
string tmp;
bool mark[16];

bool check(int a)
{
    if(a < 2)
        return false;

    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a %  i == 0)
            return false;
    }

    return true;
}

void ss(int idx)
{
    if(idx == tmp.size())
    {
        int factor = 1, answer = 0;
        for(int i = tmp.size(); i >= 1; i--)
        {
            if(mark[i])
            {
                answer += (factor * (tmp[i] - '0'));
                factor *= 10;
            }
        }

        if(check(answer))
            res = max(res, answer);

        return;
    }

    mark[idx] = true;
    ss(idx + 1);
    mark[idx] = false;
    ss(idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x;

    if(check(x))
    {
        cout << x;

        return 0;
    }

    tmp = to_string(x);
    tmp = ' ' + tmp;
    ss(0);
    
    cout << res;

    return 0;
}
