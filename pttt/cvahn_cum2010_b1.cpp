#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, i = 2, res = 0;
    cin >> n;
    int t = n;

    while(n > 1)
    {
        if(n % i == 0)
        {
            res += i;
            n /= i;
            a.push_back(i);
        }
        else
            i++;
    }
    
    cout << t << '=' << a[0];
    for(int i = 1; i < a.size(); i++)
        cout << '*' << a[i];
    cout << '\n';
    cout << res;
    return 0;
}
