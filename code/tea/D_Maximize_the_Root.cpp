#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ddfs(int node,const vector<vector<int>>& g,const vector<ll>& a){
    if(g[node].size()==0) return a[node];
    else{
        ll mmin = -1;
        for(auto nxt : g[node]){
            ll t = ddfs(nxt,g,a);
            if(mmin == -1 || mmin > t){
                mmin = t;
            }
        }
        ll v = a[node];
        if(mmin != -1 && mmin > v) return (mmin + v) / 2;
        return v;
    }
}

void solve(){
    int n;cin>>n;
    vector<vector<int>> g(n+1);
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        int t;
        cin>>t;
        g[t].push_back(i);
    }
    ll mmin = -1;
    for(auto p : g[1]){
        ll t = ddfs(p,g,a);
        if(mmin == -1 || mmin > t){
            mmin = t;
        }
    }
    ll ans = a[1] + mmin;
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