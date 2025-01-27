// cses
// Two Sets 
// https://cses.fi/problemset/task/1092/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
long long n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    //cout << n * (n + 1) / 2 << '\n';
    if((n * (n + 1) / 2) % 2 == 1)
        cout << "NO";
    else {
        int cnt = n;
        long long summe = 0;
        vector<int> set1, set2;
        while(cnt) {
            if(summe + cnt <= (n * (n + 1) / 2) / 2) {
                summe += cnt;
                set1.push_back(cnt);
            } else 
                set2.push_back(cnt);
            cnt--;
        }
        cout << "YES" << '\n';
        cout << set1.size() << '\n';
        for(int i : set1) 
            cout << i << ' ';
        cout << '\n';
        cout << set2.size() << '\n';
        for(int i : set2)
            cout << i << ' ';
    }

    return 0;
}