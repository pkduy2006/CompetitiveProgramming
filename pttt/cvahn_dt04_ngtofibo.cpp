#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> f, f_prime;

bool check(int x)
{
    if(x < 2)
        return false;

    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

int convert(vector<int> digit)
{
    int factor = 1, answer = 0;
    for(int i = digit.size() - 1; i >= 0; i--)
    {
        answer += digit[i] * factor;
        factor *= 10;
    }

    return answer;
}

bool check_2(int x)
{
    vector<int> digit;
    int example = x;
    while (x > 0)
    {
        digit.push_back(x % 10);
        x /= 10;
    }

    if(digit.size() == 2)
    {
        int tmp = convert(digit);
        if(check(tmp) && digit.front() != 0)
            return true;
    }

    while (next_permutation(digit.begin(), digit.end()))
    {
        int tmp = convert(digit);
        if(check(tmp) && digit.front() != 0)
            return true;
    }

    return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NGTOFIB.inp","r",stdin);
    freopen("NGTOFIB.out","w",stdout);

    cin >> n;
    f.push_back(1);
    f.push_back(1);
    while (f[f.size() - 1] + f[f.size() - 2] <= n)
        f.push_back(f[f.size() - 1] + f[f.size() - 2]);
    
    for(int i = 0; i < f.size(); i++)
    {
        if(check(f[i]))
            f_prime.push_back(f[i]);
    }

    for(int i = 0; i < f_prime.size(); i++)
    {
        if(check_2(f_prime[i]))
            cout << f_prime[i] << '\n';
    }

    return 0;
}
