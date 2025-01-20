// Codeforces Round 166 (Div. 2) B. Prime Matrix
// https://codeforces.com/problemset/problem/271/B

#include <bits/stdc++.h>
using namespace std;

const int N = 506;
const int PRIME_MAX = 1e5 + 3;
int n, m, a[N][N], sx[N], sy[N];
bool mark[PRIME_MAX + N];

vector<int> sieve() {
    vector<int> answer;
    for(int i = 2; i <= sqrt(PRIME_MAX); i++) {
        if(!mark[i]) {
            for(int j = i * i; j <= PRIME_MAX; j += i)
                mark[j] = true;
        }
    }
    for(int i = 2; i <= PRIME_MAX; i++) {
        if(!mark[i])
            answer.push_back(i);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    vector<int> prime = sieve();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int tmp = lower_bound(prime.begin(), prime.end(), a[i][j]) - prime.begin();
            a[i][j] = prime[tmp] - a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            sx[i] += a[i][j];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) 
            sy[i] += a[j][i];
    }
    cout << min(*min_element(sx + 1, sx + 1 + n), *min_element(sy + 1, sy + 1 + m));

    return 0;
}