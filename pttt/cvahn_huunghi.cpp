#include <bits/stdc++.h>
using namespace std;
int i,t,j,n,k;
int TheRealUoc(int n)
{
    int sum=1;
    for(int i=2; i<=sqrt(n);i++)
    if(n%i==0)
    {
        sum+=i;
        if(n/i>i)
            sum+=n/i;
    }
    return sum;
}
int main()
{
   cin >> n;
   for(int i=1; i<=n; i++)
   {
       t=TheRealUoc(i);
       k=TheRealUoc(t);
       if(k==i&&t>i&&t<=n)
        cout << i << " " << t << endl;
   }
   return 0;
}
