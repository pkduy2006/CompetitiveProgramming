// Codeforces Round 1003 (Div. 4) G. Skibidus and Capping
// https://codeforces.com/contest/2065/problem/G

#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N = 2e5 + 7;
int ntests, n, a[N];
bool mark[N];

void buildPrime() {
    fill(mark, mark + N, true);
    mark[0] = mark[1] = false;
    for(int i = 2; i <= sqrt(N); i++) {
        if(mark[i]) {
            for(int j = i * i; j < N; j += i) 
                mark[j] = false;
        }
    }
}

vector<int> findDivisor(int x) {
    vector<int> divisors;
    for(int i = 1; i <= sqrt(x); i++) {
        if(x % i == 0) {
            divisors.push_back(i);
            if(i * i != x)
                divisors.push_back(x / i);
        }
    }
    return divisors;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    buildPrime();
    cin >> ntests;
    while(ntests--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        map<int, int> mp;
        map<int, int> mp_prime;
        long long res = 0;
        for(int i = 1; i <= n; i++) {
            if(mark[a[i]])
                mp_prime[a[i]]++;
            mp[a[i]]++;
        }
        long long sum = 0;
        for(const auto& i : mp_prime) 
            sum += i.second;
        for(const auto& i : mp_prime) {
            sum -= i.second;
            res += i.second * sum;
        }
        //cout << res << '\n';
        /*for(const auto& i : mp) 
            cout << i.first << ' ' << i.second << '\n';*/
        for(const auto& i : mp) {
            if(mark[i.first])
                continue;
            vector<int> divisor = findDivisor(i.first);
            if(divisor.size() == 3) {
                sort(divisor.begin(), divisor.end());
                /*for(int x : divisor)
                    cout << x << ' ';
                cout << '\n';*/
                if(mark[divisor[1]]) {
                    res += (long long)mp[divisor[1]] * mp[divisor[2]];
                    res += (long long)mp[divisor[2]] * mp[divisor[2]] - (mp[divisor[2]] * (mp[divisor[2]] - 1) / 2);
                }
            } else if(divisor.size() == 4) {
                sort(divisor.begin(), divisor.end());
                if(mark[divisor[1]] && mark[divisor[2]]) {
                    res += (long long)mp[divisor[1]] * mp[divisor[3]];
                    res += (long long)mp[divisor[2]] * mp[divisor[3]];
                    res += (long long)mp[divisor[3]] * mp[divisor[3]] - (mp[divisor[3]] * (mp[divisor[3]] - 1) / 2);
                }
            }
            //cout << i.first << ' ' << res << '\n';
        }
        cout << res << '\n';
    }
    /*vector<int> checker = findDivisor(4);
    for(int x : checker)
        cout << x << ' ';*/

    return 0;
}