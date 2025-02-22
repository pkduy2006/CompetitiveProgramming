#include <iostream>
using namespace std;
string a, c;
long long i, b, du;
string chiaslsn(string a, long long b) {
    string c = "";
    du = 0;
    for (i = 0; i < a.length(); i++) {
        du = du * 10 + a[i] - 48;
        c = c + char(du / b + 48);
        du = du % b;
    }
    while (c[0] == '0' && c.length() > 1)
        c.erase(0, 1);
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    cout << chiaslsn(a, b) << endl << du << endl;
    return 0;
}
