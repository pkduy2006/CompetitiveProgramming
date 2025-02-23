#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<string> divisor;

bool cmp(string me, string her)
{
    return me + her > her + me;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Taoso.inp","r",stdin);
    freopen("Taoso.out","w",stdout);

    cin >> n;

    int tmp = n;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            while (tmp % i == 0)
            {
                divisor.push_back(to_string(i));
                tmp /= i;
            }
        }
    }

    if(tmp != 1)
        divisor.push_back(to_string(tmp));

    sort(divisor.begin(), divisor.end(), cmp);

    for(int i = 0; i < divisor.size(); i++)
        cout << divisor[i];
    
    return 0;
}
