#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
bool isPrime[N];
vector <int> Prime;
int k, test, d, n;

void Eratosthene()
{
    for(int i = 2; i < N; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i*i < N; i++)
        if(isPrime[i])
            for(int j = i*i; j < N; j += i)
                isPrime[j] = 0;
    for(int i = 0; i < N; i++) if(isPrime[i]) Prime.push_back(i);
    d = Prime.size();
}

main()
{
    freopen("tichnt.inp","r",stdin);
    freopen("tichnt.out","w",stdout);
    
    Eratosthene();
    cin >> n >> k;
    int res = 0;
    for(int i = 0; i < d - k + 1; i++){
        int s = 1;
        for(int j = i; j < i + k; j++)
            s *= Prime[j];
        if(s > n) break;
        else res = max(res, s);
    }
    if(res != 0) cout << res;
    else cout << -1;
    return 0;
    }
