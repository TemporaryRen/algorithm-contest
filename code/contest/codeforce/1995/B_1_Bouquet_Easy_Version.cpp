#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll totalcost = 0;
    ll ans = 0;
    int l = n-1;
    for(int i=n-1;i>=0;--i){
        if(a[i] > m) continue;
        while(totalcost + a[i] > m){
            totalcost -= a[l];
            l --;
        }
        while(a[l] - a[i] > 1){
            totalcost -= a[l--];
        }
        totalcost += a[i];
        ans = max(ans,totalcost);
    }
    cout<<ans<<"\n";
    
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