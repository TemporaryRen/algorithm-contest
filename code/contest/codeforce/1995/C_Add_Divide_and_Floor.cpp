#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    int a = 1e9 + 1,b = 0,t;
    for(int i=0;i<n;i++){
        cin>>t;
        a = min(a,t);
        b = max(b,t);
    }
    if(a == b){
        cout<<0<<"\n";
        return;
    }
    int ans = (1 << (32 - __builtin_clz(b))) - 1 - b;
    a += ans;
    b += ans;
    int cnt = 32 - __builtin_clz(a^b);
    cout<<cnt<<"\n";
    if(cnt <= n){
        cout<<ans;
        for(int i=0;i<cnt-1;i++) cout<<" "<<0;
        cout<<"\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}