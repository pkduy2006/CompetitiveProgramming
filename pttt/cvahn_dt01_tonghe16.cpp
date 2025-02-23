#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c;

int chuyen(char a){
    if(a-48<10){
        return a-48;
    }
    if(a == 'A') return 10;
    if(a == 'B') return 11;
    if(a == 'C') return 12;
    if(a == 'D') return 13;
    if(a == 'E') return 14;
    if(a == 'F') return 15;
}
string congsl(string a,string b){
    int i, nho = 0;
    while(a.length() < b.length()) a = '0' + a;
    while(a.length() > b.length()) b = '0' + b;
    for(i = a.length()-1; i >= 0; i--)
    {
        nho = nho + chuyen(a[i]) + chuyen(b[i]);
        if(nho % 16 >= 10)
        {
            int j = nho % 16;
            if(j == 10) c = 'A' + c;
            if(j == 11) c = 'B' + c;
            if(j == 12) c = 'C' + c;
            if(j == 13) c = 'D' + c;
            if(j == 14) c = 'E' + c;
            if(j == 15) c = 'F' + c;
        }
        else
        {
                c = (char)(nho%16+48) + c;
        }
        nho = nho / 16;
    }

    c = (char)(nho%16+48) + c;
    while(c[0] == '0'&&c.length() > 1) c.erase(0,1);
    return c;
}


main()
{
    freopen("tonghe16.inp","r",stdin);
    freopen("tonghe16.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    cout<<congsl(a,b);
    
    return 0;
}
