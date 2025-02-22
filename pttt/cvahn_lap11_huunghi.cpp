#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<int, int>> res;

int countRealDivisor(int k)
{
    int answer = 1;
    for(int i = 2; i <= sqrt(k); i++)
    {
        if(k % i == 0)
        {
            answer += i;
            if(i * i != k)
                answer += k / i;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int tmp = countRealDivisor(i);
        if(countRealDivisor(tmp) == i && i != tmp && tmp <= n)
            res.insert({min(i, tmp), max(i, tmp)});
    }

    if(res.size() == 0)
    {
        cout << 0;
        return 0;
    }

    for(auto x : res)
        cout << x.first << ' ' << x.second << '\n';
    
    return 0;
}
