#include <bits/stdc++.h>
#define int long long
using namespace std;
stack<int> TenToEight(int t)
{
    stack<int> ans;
    while(t > 0)
    {
        ans.push(t % 8);
        t /= 8;
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<int> res = TenToEight(n);
    while(!res.empty())
    {
        cout << res.top();
        res.pop();
    }
    return 0;
}
