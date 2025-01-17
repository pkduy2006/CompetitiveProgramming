#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int vasen = 0, oikea = x / 2;
        while(vasen <= oikea) {
            int keskella = (vasen + oikea) / 2;
            if((long long)keskella * keskella <= x)
                vasen = keskella + 1;
            else
                oikea = keskella - 1;
        }
        return oikea;
    }
}solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << solution.mySqrt(4) << '\n';
    cout << solution.mySqrt(8) << '\n';
    cout << solution.mySqrt(2147395599) << '\n';

    return 0;
}