#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    ll N;
    cin>>N;
    if(N==1){
        cout<<"0\n";
        return;
    }
    N -= 2;
    ll p = 9;
    while(N >= 2 * p){
        N -= 2 * p;
        p = p * 10 ;
    }
    //1 9
    //2 9
    //
    string s = to_string(N % p + p / 9);
    string t = s;
    reverse(t.begin(),t.end());
    if(N<p){
        s.pop_back();
    }
    s += t;
    cout<<s<<"\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}