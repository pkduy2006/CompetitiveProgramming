// lqdoj
// CSES - Gray Code | Mã Gray
// https://lqdoj.edu.vn/problem/cses2205

#include <bits/stdc++.h>
using namespace std;

int n;

vector<string> GrayCodeGeneration(int x) {
    if(x == 0) 
        return {""};
    vector<string> prev = GrayCodeGeneration(x - 1);
    vector<string> result;
    for(string code : prev)
        result.push_back("0" + code);
    for(auto it = prev.rbegin(); it != prev.rend(); it++)
        result.push_back("1" + *it);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    vector<string> answer = GrayCodeGeneration(n);
    for(string a : answer)
        cout << a << '\n';

    return 0;
}