#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, res=0;
    cin >> n;
    vector<int> mark(n+1);
    for(int i=2; i<=sqrt(n); i++)
    {
        if(mark[i]==0)
        {
            for(int j=2*i; j<=n; j+=i)
                mark[j]=1;
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(mark[i]==0)
            res++;
    }
    cout << res;
    return 0;
}
