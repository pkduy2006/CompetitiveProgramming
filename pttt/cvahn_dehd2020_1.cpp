#include <bits/stdc++.h>
using namespace std;

int xA, yA, xC, yC, xM, yM, xN, yN, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> xA >> yA >> xC >> yC >> xM >> yM >> xN >> yN;

    if(((xA < xM && xM < xC) || (xC < xM && xM < xA)) && ((yA < yM && yM < yC) || (yC < yM && yM < yA)))
        res++;
    if(((xA < xN && xN < xC) || (xC < xN && xN < xA)) && ((yA < yN && yN < yC) || (yC < yN && yN < yA)))
        res++;

    cout << res;

    return 0;
}
