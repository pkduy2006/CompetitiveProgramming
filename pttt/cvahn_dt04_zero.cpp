#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> remain_num;
set<int> res;

void ss(int a)
{
    for(int i = 1; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            int x = min(i, a / i), y = max(i, a / i);
            x--;
            y++;

            if(x * y != 0)
            {
                if(res.count(x * y) == 0)
                    remain_num.push_back(x * y);
                res.insert(x * y);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("zero.inp","r",stdin);
    freopen("zero.out","w",stdout);

    cin >> n;

    remain_num.push_back(n);
    while (!remain_num.empty())
    {
        int tmp = remain_num.front();
        remain_num.erase(remain_num.begin());
        ss(tmp);
    }
    res.insert(0);

    cout << res.size() << '\n';
    for(auto it = res.begin(); it != res.end(); it++)
        cout << (*it) << ' ';

    return 0;
}
