#include <bits/stdc++.h>
using namespace std;

int n, loai;
map<string, int> mdemtu;
string tu;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> loai >> tu;
        if (loai == 1) mdemtu[tu]++;
        else cout << mdemtu[tu] << '\n';
    }
    return 0;
}
