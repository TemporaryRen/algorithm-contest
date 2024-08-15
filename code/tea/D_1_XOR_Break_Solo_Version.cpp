#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    if((n^m)<n){
        cout<<1<<"\n";
        cout<<n<<" "<<m<<"\n";
    }else{
        ll hhi = 1LL << (63 - __builtin_clzll(n));
        if((n^hhi) > 0){
            ll x = (1LL << (64 - __builtin_clzll(n^hhi))) - 1;
            if(x >= m){
                cout<<2<<"\n";
                cout<<n<<" "<<x<<" "<<m<<"\n";
                return;
            }
        }
        cout<<-1<<"\n";
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