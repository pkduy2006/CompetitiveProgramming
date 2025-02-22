#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e2 + 16;
int n, a[N], res = 0;

vector<pair<int, int>> extract(int value)
{
    vector<pair<int, int>> answer;
    int k = value;

    for(int i = 2; i <= sqrt(value); i++)
    {
        if(k % i == 0)
        {
            int cnt = 0;
            while (k % i == 0)
            {
                k /= i;
                cnt++;
            }
            
            answer.push_back({i, cnt});
        } 
    }

    if(k != 0)
        answer.push_back({k, 1});

    return answer;
}

bool check(int value)
{
    vector<pair<int, int>> prime = extract(value);

    for(int i = 0; i < prime.size(); i++)
    {
        auto [x, y] = prime[i];

        if((value - 1) / x < y)
            return false;
    }

    return true;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);
    //freopen("input.txt","r",stdin);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {   
        cin >> a[i];
        
        if(check(a[i]) || a[i] == 1) 
            res++;
    }
    
    cout << res << '\n';

    return 0;
}
