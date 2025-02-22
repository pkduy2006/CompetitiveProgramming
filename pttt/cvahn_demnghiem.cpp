#include <bits/stdc++.h>
using namespace std;
int main()
{
    float a, b, c;
    int res=0;
    cin >> a >> b >> c;
    for(int i=1; i<=c; i++)
    {
        float y=(c-a*i)/b;
        if(y==(int)y&&y>0)
            res++;
    }
    cout << res;
    return 0;
}
