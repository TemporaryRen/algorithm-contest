#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll> a;
    a.push_back(n);
    for(int i=0;(1ll<<i)<n;i++){
        if(n&(1ll<<i)) a.push_back(n-(1ll<<i));
    }
    int ans = a.size();
    cout<<ans<<"\n";
    for(int i=ans-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

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