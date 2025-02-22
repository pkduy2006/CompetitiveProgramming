#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100071], mark[100072];
vector< pair <int, int> > cnt;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    cnt.push_back(make_pair(a[1], 1));
    for(int i = 2; i <= n; i++)
    {
        if(a[i] == a[i - 1])
            cnt[cnt.size() - 1].second++;
        else
            cnt.push_back(make_pair(a[i], 1));
    }
    for(int i = 0; i < cnt.size(); i++)
        cout << cnt[i].first << ':' << cnt[i].second << '\n';
    return 0;
}
