#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e6 + 16;
int a, b, lp[M];
bool mark[M];

void sieve()
{
    mark[0] = mark[1] = true;

    for(int i = 2; i <= sqrt(M); i++)
    {
        if(!mark[i])
        {
            for(int j = i * i; j <= M; j += i)
                mark[j] = true;
        }
    }

  //  for(int i = 2; i <= 10; i++)
  //      cout << i << ' ' << mark[i] << '\n';


    for(int i = 2; i < M; i++)
    {
        lp[i] = lp[i - 1];
        if(!mark[i])
            lp[i]++;
    }

   // for(int i = 2; i <= 10; i++)
    //    cout << i << ' ' << mark[i] << '\n';

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cp.inp","r",stdin);
    freopen("cp.out","w",stdout);

    cin >> a >> b;

    sieve();

    //for(int i = a; i <= b; i++)
    //    cout << i << ' ' << mark[i] << '\n';

    int x = sqrt(a);
    if(x * x < a)
        x++;
    int y = sqrt(b);

    cout << lp[y] - lp[x - 1];

    return 0;
}
