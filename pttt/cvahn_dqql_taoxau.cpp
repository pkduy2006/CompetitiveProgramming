#include<bits/stdc++.h>
using namespace std;
int n,i,j;
string s;
void taoxau(int i)
{
    for(char j='A';j<='B';j++)
        if(j=='A'||(j=='B'&&s[i-1]!='B'))
        {
            s[i]=j;
            if(i==n-1) cout<<s<<endl;
            else taoxau(i+1);
        }
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        s=s+'0';
    taoxau(0);
    return 0;
}
