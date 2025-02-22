#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 11;
string s;
vector<int> a;

bool check()
{
    int cnt = 0;
    bool review = false;
    for(int i = 0; i < s.size(); i++)
    {
        cnt += (s[i] - '0');
        
        if(s[i] == '0')
            review = true;
    }

    return (review && cnt % 3 == 0);
}

void convert()
{
    for(int i = 0; i < s.size(); i++)
        a.push_back(s[i] - '0');

    sort(a.rbegin(), a.rend());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI7.inp","r",stdin);
    freopen("BAI7.out","w",stdout);

    cin >> s;
    
    if(!check())
    {
        cout << -1;

        return 0;
    }

    convert();
    for(int i = 0; i < a.size(); i++)
        cout << a[i];

    return 0;
}
