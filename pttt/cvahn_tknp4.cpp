#include <bits/stdc++.h>
#define int long long 
using namespace std;

string hamburger;
int nb, ns, nc, pb, ps, pc, r, b, s, c; 

bool check(int cnt)
{
    int money = r - pb * max(cnt * b - nb, 0ll) - ps * max(cnt * s - ns, 0ll) - pc * max(cnt * c - nc, 0ll);

    return money >= 0;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   //freopen("input.txt","r",stdin);

    cin >> hamburger >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for(int i = 0; i < hamburger.size(); i++)
    {
        if(hamburger[i] == 'B')
            b++;
        else if(hamburger[i] == 'S')
            s++;
        else
            c++;
    }

    int l = 1, r = (int)1e15;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if(check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << r;
    
    return 0;
}
