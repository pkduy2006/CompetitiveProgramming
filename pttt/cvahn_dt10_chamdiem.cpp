#include <bits/stdc++.h>
using namespace std;
int n,loai;
map<string, int> mdiem;
string hsinh;
int kqua;
int main()
{
    
    cin>>n;
    while (n--)
    {
        cin>>loai>>hsinh;
        if(loai==1){cin>>kqua; mdiem[hsinh]=mdiem[hsinh]+kqua;}
         else if(loai==2) mdiem[hsinh]=0;
        else cout<<mdiem[hsinh]<<endl;
    }
    return 0;
    }
