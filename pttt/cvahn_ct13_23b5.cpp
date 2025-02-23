#include <bits/stdc++.h>
#define int long long
using namespace std;

const int BASE = 10000;

void fix(vector<int> &t)
{
    t.push_back(0);

    for(int i = 0; i < t.size() - 1; ++i)
    {
        t[i + 1] += t[i] / BASE;
        t[i] %= BASE;

        if(t[i] < 0)
        {
            t[i] += BASE;
            t[i + 1]--;
        }
    }

    while(t.size() >= 2 && t.back() == 0)
        t.pop_back();
}

vector<int> operator+(vector<int> t, const vector<int> &h)
{
    t.resize(max(t.size(), h.size()));

    for(int i = 0; i < h.size(); ++i)
        t[i] += h[i];

    return fix(t), t;
}

vector<int> operator-(vector<int> t, const vector<int> &h)
{
    t.resize(max(t.size(), h.size()));

    for(int i = 0; i < h.size(); ++i)
        t[i] -= h[i];

    return fix(t), t;
}

vector<int> operator/(vector<int> t, int x)
{
    for(int i = t.size() - 1, r = 0; i >= 0; --i, r %= x)
    {
        r = r * BASE + t[i];
        t[i] = r / x;
    }

    return fix(t), t;
}

istream &operator>>(istream &cin, vector<int> &t)
{
     string s;
     cin >> s;
     t.clear();
     t.resize(s.size() / 4 + 1);
     for(int i = 0; i < s.size(); ++i)
     {
         int x = (s.size() - 1 - i) / 4;
         t[x] = t[x] * 10 + (s[i] - '0');
     }

     return fix(t), cin;
}

ostream &operator<<(ostream &cout, const vector<int> &t)
{
    printf("%d", t.back());
    for(int i = t.size() - 2; i >= 0; i--)
        printf("%04d", t[i]);
    printf("\n");
    return cout;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> t, h;
    cin >> t >> h;
    cout << (t + h) / 2 << (t - h) / 2;

    return 0;
}
