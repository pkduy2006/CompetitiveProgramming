#include <bits/stdc++.h>
#define int long long
using namespace std;
pair <int, int> project[100083];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s, res = 0;
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        cin >> project[i].first >> project[i].second;
    sort(project + 1, project + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        if(s >= project[i].first)
        {
            res++;
            s+=project[i].second;
        }
        else
            break;
    }
    cout << res;
    return 0;
}
