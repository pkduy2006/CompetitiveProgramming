#include <bits/stdc++.h>
using namespace std;

map<string, int> dsdiem;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int loai; cin >> loai;
        if (loai == 1)
        {
            string ten; int diem;
            cin >> ten >> diem;
            dsdiem[ten] += diem;
        }
        else if (loai == 2)
        {
            string ten; cin >> ten;
            dsdiem.erase(ten);
        }
        else
        {
            string ten; cin >> ten;
            cout << dsdiem[ten] << '\n';
        }
    }
    return 0;
}
