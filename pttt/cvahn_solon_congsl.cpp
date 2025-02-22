#include <bits/stdc++.h>
#define int long long
using namespace std;

vector <int> a, b, res;

void Sum(vector<int> a, vector<int> b)
{
    while(a.size() < b.size())
        a.insert(a.begin(), 0);
    while(b.size() < a.size())
        b.insert(b.begin(), 0);
    int carry = 0, sum = 0;

    for(int i = a.size() - 1; i >= 0; i--)
    {
        sum = a[i] + b[i] + carry;
        carry = sum / 10;
        res.push_back(sum % 10);
        //cout << a[i] << ' ' << ' ' << b[i] << ' ' << sum << '\n';
    }

    reverse(res.begin(), res.end());
    if(carry > 0)
        res.insert(res.begin(), 1);

}

main()
{
    //freopen("SumBigNum.inp","r",stdin);
    //freopen("SumBigNum.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x, y;
    cin >> x >> y;
    for(int i = 0; i < x.size(); i++)
        a.push_back(x[i] - '0');
    for(int i = 0; i < y.size(); i++)
        b.push_back(y[i] - '0');

    Sum(a, b);
    for(int i = 0; i < res.size(); i++)
        cout << res[i];
    return 0;
}
