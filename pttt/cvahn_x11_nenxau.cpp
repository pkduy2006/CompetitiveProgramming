#include<bits/stdc++.h>
using namespace std;
string them(int a){
    string b = to_string(a);
    return b;
}
int main(){
    freopen("NENXAU.inp","r",stdin);
    freopen("NENXAU.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(0);
    string s;
    cin >> s;
    //cout << s << endl;
    for(int i = 0; i < s.size(); i++){
       if(s[i] < 'a'){
           s[i] = s[i] + 32;
       }
    }
    char cur = s[0];
    int dem = 0;
    string ans;
    int vt;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != cur){
            if(dem > 2){
                ans = ans + them(dem) + cur; 
            }
            else if(dem == 1){
                ans = ans + cur;
            }
            else if(dem == 2){
                ans = ans + cur + cur;
            }
            cur = s[i];
            dem = 1;
            vt = i;
        }
        else{
            dem++;
        }
    }
    if(dem > 2){
        ans = ans + them(dem) + cur; 
    }
    if(dem == 1){
        ans = ans + cur;
    }
    if(dem == 2){
        ans = ans + cur + cur;
    }
    cout << ans;
}
