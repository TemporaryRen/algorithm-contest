#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];
    int k;
    cin>>k;
    vector<int> stk;
    ll total = 0;
    for(int i=0;i<n;i++){
        while(!stk.empty() && c[stk.back()]>=c[i]){
            stk.pop_back();
        }
        stk.push_back(i);
    }
    vector<int> ans(n,0);
    int last = -1;
    int d = 1e9 + 1;
    for(int i=0;i<stk.size();i++){
        int v;
        if(i==0) v = c[stk[i]];
        else v = c[stk[i]]-c[stk[i-1]];
        d = min(d,k/v);
        k -= d*v;
        if(d<=0) break;
        for(int j=last+1;j<=stk[i];j++) ans[j] += d;
        last = stk[i];
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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