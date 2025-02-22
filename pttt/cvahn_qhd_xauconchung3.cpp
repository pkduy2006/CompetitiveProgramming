#include<bits/stdc++.h>
using namespace std;
long long i,j,k,m,n;
string a,b,s,d;
long long c[401][401][401];
void taobang(){
    a = "@" + a;
    b = "@" + b;
    d = "@" + d;
    c[0][0][0] = 0;
    for (int i = 1; i < a.length(); i++)
        for (int j = 1; j < b.length(); j++)
            for (int k = 1; k < d.length(); k++)
                if (a[i] == b[j] && b[j] == d[k])
                    c[i][j][k] = c[i-1][j-1][k-1] + 1;
                else c[i][j][k] = max(max(c[i-1][j][k],c[i][j-1][k]),c[i][j][k-1]);
}
void truyhoi(){
	i = a.length() - 1;
	j = b.length() - 1;
	k = d.length() - 1;
    s = "";
while(c[i][j][k] > 0){
        if(c[i][j][k] == c[i-1][j][k]) i--;
        else if (c[i][j][k] == c[i][j-1][k]) j--;
        else if (c[i][j][k] == c[i][j][k-1]) k--;
        else{
            s = a[i] + s;
            i--; 
			j--;
			k--;
        }
    }
}
int main(){
	cin >> a >> b >> d;
	taobang();
	truyhoi();
	cout << s;
}
