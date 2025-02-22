#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> a;

    for(int i = 2; i <= sqrt(n); i++)
    {
        while(n % i == 0)
        {
            n /= i;
            string t = to_string(i);
            a.push_back(t);
        }
    }
    if(n != 1)
    {
        string m = to_string(n);
        a.push_back(m);
    }

    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < a.size(); i++)
        cout << a[i];
    return 0;
}
