#include <bits/stdc++.h>
using namespace std;

int a, b, res;
vector<int> ans;

int cnt_divisor(int x)
{
    int cnt = 0;
    for(int i = 1; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            cnt++;
            if(i * i != x)
                cnt++;
        }
    }

    return cnt; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("uocso.inp","r",stdin);
    freopen("uocso.out","w",stdout);

    cin >> a >> b;
    for(int i = a; i <= b; i++)
    {
        int tmp = cnt_divisor(i);
        if(tmp > res)
        {
            ans.clear();
            ans.push_back(i);
            res = cnt_divisor(i);
        }
        else if(tmp == res)
            ans.push_back(i);
    }

    cout << ans.front() << ' ' << cnt_divisor(ans.front()) << ' ' << ans.size();

    return 0;
}
