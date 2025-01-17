//Hành Trình Không Dừng
//https://lqdoj.edu.vn/problem/hanhtrinhkhongdung

#include <bits/stdc++.h>
using namespace std;

long long w, l, x;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> l >> x;

    long long numerator = x * (w + l) - 100 * w;
    long long denominator = 100 - x;
    if (numerator <= 0) 
        cout << 0 << '\n';
    else
        cout << (numerator + denominator - 1) / denominator << '\n';

    return 0;
}