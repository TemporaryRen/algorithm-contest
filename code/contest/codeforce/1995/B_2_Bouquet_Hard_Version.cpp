#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
struct flower{
    ll petal;
    ll quantity;
};
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<flower> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].petal;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].quantity;
    }
    //sorted by petal
    sort(a.begin(),a.end(),[](const auto&t1 ,const auto&t2){
        return t1.petal > t2.petal;
    });
    ll l = 0;
    ll ans = 0;
    for(int i=0;i<a.size();i++){
 
        while(a[l].petal - a[i].petal > 1){
            l++;
        }
        if(l == i){
            ll cnt2 = min(m / a[i].petal,a[i].quantity);
            ans = max(ans,cnt2*a[i].petal);
        }else{
            ll cnt1 = min(m / a[l].petal,a[l].quantity);
            ll left = m - cnt1 * a[l].petal;
            ll cnt2 = min(left / a[i].petal,a[i].quantity);
            ll left2 = left - cnt2 * a[i].petal;
            ans = max(ans,m - left2);
            ll cnt3 = a[i].petal - left2;
            if(cnt3 > 0 && (cnt3 <= cnt1) && (cnt3 + cnt2 < a[i].quantity)){
                ll ttt = (cnt1 - cnt3) * a[l].petal + (cnt3 + cnt2 + 1) * a[i].petal;
                ans = max(ans,ttt);
            }
        }
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