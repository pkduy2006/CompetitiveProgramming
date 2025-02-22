#include <bits/stdc++.h>
using namespace std;
int a[10117];
int main()
{
    int n, cnt=0, res=0, pos=0;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    n++;
    a[n]=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>0)
            cnt++;
        else
        {
            if(cnt>res)
            {
                res=cnt;
                pos=i-1;
            }
            cnt=0;
        }
    }
    cout << res << '\n';
    for(int i=pos-res+1; i<=pos; i++)
        cout << a[i] << ' ';
    return 0;
}
