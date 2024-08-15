#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> build(const vector<pair<int,int>> &edges,int n){
    //build graph
    vector<vector<int>> g(n+1);
    for(auto [x,y] : edges){
        g[x].push_back(y);
        g[y].push_back(x);
    }
    return g;
}

pair<ll,ll> cal(int cur,int fa,const vector<vector<int>> &g,const vector<ll> &a){
    ll ans1 = a[cur];
    ll ans2 = 0ll;
    for(auto nxt : g[cur]){
        if(nxt != fa){
            auto child_cal = cal(nxt,cur,g,a);
            ans1 += child_cal.second;
            ans2 += max(child_cal.first,child_cal.second);
        }
    }
    return {ans1,ans2};
}

void solve(){
    int n,e1,e2;
    ll ssum = 0;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        ssum += a[i];
    }
    vector<pair<int,int>> edges(n-1);
    for(int i=0;i<n-1;i++){
        cin>>e1>>e2;
        pair<int,int> ee = {e1,e2};
        edges[i] = ee;
    }
    vector<vector<int>> g = build(edges,n);
    auto ans = cal(1,0,g,a);
    ll tt = max(ans.first,ans.second);
    cout<<(ssum+(ssum-tt))<<"\n";

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