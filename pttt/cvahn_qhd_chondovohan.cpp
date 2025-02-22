#include <iostream>
using namespace std;

const int nm = 1e5 + 1;
int n, p, i, a[1001], b[1001], c[nm], d[nm], ans[1001];

void make_table () {
    for (int i = 1; i <= p; i++)
        for (int j = 1; j <= n; j++)
            if (i >= a[j] && (d[i] == 0 || d[i] < d[i - a[j]] + b[j])) {
                d[i] = d[i - a[j]] + b[j];
                c[i] = j;
            }
}

void Retrieval () {
    int pos = p;
    for (int i = p - 1; i >= 1; i--)
        if (d[pos] < d[i]) pos = i;
    cout << d[pos] << endl;
    while (pos > 0) {
        ans[c[pos]]++;
        pos -= a[c[pos]];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> p;
    for (i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    make_table();
    Retrieval();
    return 0;
}
