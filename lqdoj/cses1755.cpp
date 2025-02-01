// lqdoj
// CSES - Palindrome Order | Sắp xếp lại xâu đối xứng
// https://lqdoj.edu.vn/problem/cses1755

#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26], a;
string middle = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for(char c : s)
        cnt[c - 'A']++;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] % 2 != 0) {
            middle = (char)(i + 'A');
            a++;
        }
    }
    if(a >= 2)
        cout << "NO SOLUTION";
    else {
        string res = "";
        for(int i = 0; i <= 25; i++) {
            for(int j = 1; j <= cnt[i] / 2; j++)
                res += (char)(i + 'A');
        }
        res += middle;
        for(int i = 25; i >= 0; i--) {
            for(int j = 1; j <= cnt[i] / 2; j++)
                res += (char)(i + 'A');
        }
        cout << res;
    }
    return 0;
}