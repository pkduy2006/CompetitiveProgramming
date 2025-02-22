#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int res = 0, si;
    cin >> si >> s;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 2; j <= s.size(); j++)
        {
            string ans = s.substr(i, j);
            string review = ans;
            reverse(ans.begin(), ans.end());
            if(review == ans && review.size() > res)
                res = review.size();
        }
    }
    cout << res;
    return 0;
}
