#include <bits/stdc++.h>
#define int long long
#define task "CntDivisors."
#define inf 1e9 + 7
#define x first
#define y second
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], is_prime[maxn], smallest_factor[maxn];
int cnt[maxn],not_scp = 0;
void eratosthenes_sieve(int max_value)
{
    fill(is_prime, is_prime + 1 + max_value, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= max_value; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= max_value; j += i)
            {
                is_prime[j] = false;

                if (!smallest_factor[j])
                    smallest_factor[j] = i;
            }

    for (int i = 2; i <= max_value; ++i)
        if (is_prime[i])
            smallest_factor[i] = i;
}

void cnt_divisors(int N)
{
    vector<int> num;
    while(N > 1)
    {
        int nt = smallest_factor[N];
        num.push_back(nt);
        N /= smallest_factor[N];
    }
    num.push_back(-1);
    int sl = 1;
    for(int i = 0; i < num.size()-1;i++)
    {
        if(num[i] == num[i+1])
            sl++;
        else
        {
            if(cnt[num[i]]%2 == 0 && (cnt[num[i]]+sl)%2 == 1)
                not_scp++;
            else if(cnt[num[i]]%2 == 1 && (cnt[num[i]]+sl)%2 == 0)
                not_scp--;
            cnt[num[i]] += sl;
            sl = 1;
        }
    }
}
main()
{
    freopen("sqrnum.inp","r",stdin);
    freopen("sqrnum.out","w",stdout);
    eratosthenes_sieve(1000000);
    int n;
    cin >> n;
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
        cnt_divisors(a[i]);
        if(not_scp <= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
