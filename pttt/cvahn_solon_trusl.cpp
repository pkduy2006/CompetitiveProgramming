#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a, b, res;

void Difference(vector<int> a, vector<int> b)
{
    while(a.size() < b.size())
        a.insert(a.begin(), 0);
    while(b.size() < a.size())
        b.insert(b.begin(), 0);

    int difference = 0, borrow = 0;

    for(int i = a.size() - 1; i >= 0; i--)
    {
        difference = a[i] - b[i] - borrow;
        //cout << difference << ' ';
        if(difference < 0)
        {
            difference += 10;
            borrow = 1;
            //cout << difference << '\n';
        }
        else
            borrow = 0;

        res.push_back(difference);
    }

    reverse(res.begin(), res.end());
    while(res.size() >= 2 && res.front() == 0)
        res.erase(res.begin());
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x, y;
    cin >> x >> y;
    for(int i = 0; i < x.size(); i++)
        a.push_back(x[i] - '0');
    for(int i = 0; i < y.size(); i++)
        b.push_back(y[i] - '0');

    if(a.size() > b.size())
        Difference(a, b);
    else if(a.size() < b.size())
    {
        Difference(b, a);
        cout << '-';
    }
    else
    {
        bool check = true;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            if(a[i] < b[i])
            {
                check = false;
                break;
            }
        }

        if(check == false)
        {
            Difference(b, a);
            cout << '-';
        }
        else
            Difference(a, b);
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i];
    return 0;
}
