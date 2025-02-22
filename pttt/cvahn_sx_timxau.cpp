#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 3;

string s[N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, cnt = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    sort(s + 1, s + 1 + n);

    string first = s[1];
    for(int i = 2; i <= n; i++)
    {
        if(first != s[i])
        {
            if(cnt % 2 != 0)
            {
                cout << first;
                return 0;
            }
            else
            {
                first = s[i];
                cnt = 1;
            }
        }
        else
            cnt++;
    }
    if(cnt % 2 == 1)
        cout << first << '\n';
    return 0;
}
