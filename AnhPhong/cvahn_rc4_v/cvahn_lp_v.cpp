#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
const long long base = 31, MOD = 1e9 + 7;
string s, t;
int n, pos, sz;
long long hashS[N], hashT[N], power[N];

void Build()
{
    power[0] = 1;
    for(int i = 1; i <= n; i++)
        power[i] = (power[i - 1] * base) % MOD;
    
    for(int i = 1; i <= n; i++)
        hashS[i] = (hashS[i - 1] * base + s[i] - 'a' + 1) % MOD;
    for(int i = 1; i <= n; i++)
        hashT[i] = (hashT[i - 1] * base + t[i] - 'a' + 1) % MOD;
}

long long getS(int x, int y)
{
    return (hashS[y] - hashS[x - 1] * power[y - x + 1] + MOD * MOD) % MOD;
}

long long getT(int x, int y)
{
    return (hashT[y] - hashT[x - 1] * power[y - x + 1] + MOD * MOD) % MOD;
}

bool check(int len)
{
    for(int i = 1; i <= n - len + 1; i++)
    { 
        if(getS(i, i + len - 1) == getT(n - i - len + 2, n - i + 1))
        {   
            if(len > sz)
            {
                pos = i;
                sz = len;
            }

            return true;
        }
    }

    return false;
}

void BinarySearchOddValue()
{
    int l = 1, r = (s.size() % 2 == 1 ? s.size() : s.size() - 1);

    while (l <= r)
    {
        int mid = (l + r) / 2;
        mid -= (mid % 2 == 0);

        if(check(mid))
            l = mid + 2;
        else
            r = mid - 2;
    }
}

void BinarySearchEvenValue()
{
    int l = 2, r = (s.size() % 2 == 0 ? s.size() : s.size() - 1);

    while (l <= r)
    {
        int mid = (l + r) / 2;
        mid -= (mid % 2 == 1);

        if(check(mid))
            l = mid + 2;
        else
            r = mid - 2; 
    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LP.inp","r",stdin);
    freopen("LP.out","w",stdout);
   // freopen("input.txt","r",stdin);

    cin >> s;
    
    t = s;
    reverse(t.begin(), t.end());
    n = t.size();
    t = ' ' + t;
    s = ' ' + s;
    Build();

    BinarySearchEvenValue();
    BinarySearchOddValue();

    cout << s.substr(pos, sz);

    return 0;
}
