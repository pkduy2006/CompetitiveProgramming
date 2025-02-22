#include <bits/stdc++.h>
using namespace std;
vector<long long> n;
long long p[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int main()
{
    long long a, b, cnt=2;
    cin >> a >> b;
    for(long long i=0; i<8; i++)
    {
        for(long long j=2; j<=p[i]; j++)
            cnt*=2;
        n.push_back(cnt/2*(cnt-1));
        cnt=2;
    }
    for(long long i=a; i<=b; i++)
    {
        for(long long j=0; j<n.size(); j++)
        {
            if(i==n[j])
                cout << i << ' ';
        }
    }
    return 0;
}
