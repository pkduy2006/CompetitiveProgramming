#include<bits/stdc++.h>
using namespace std;

const int nm = 1e4 + 1;
int n, i, sum, sum1, a[nm], c[500 * nm];
bool check[nm];

void make_table () {
    for (int i = 1; i <= sum1; i++) {
        c[i] = INT_MAX;
        for (int j = 1; j <= n; j++)
            if (i >= a[j] && j > c[i - a[j]]) {
                c[i] = j;
                break;
            }
    }
}

void Retrieval () {
    while (c[sum1] == INT_MAX) sum1--;
    cout << sum1 << endl;
    cout << sum - sum1 << endl;
    while (sum1 > 0) {
        check[c[sum1]] = 1;
        sum1 -= a[c[sum1]];
    }
    for (int i = 1; i <= n; i++)
        if (check[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum1 = sum / 2;
    make_table();
    Retrieval();
    return 0;
}
