#include <bits/stdc++.h>
using namespace std;
#define ll long long

int parity(const vector<int> &a) {
    const int n = a.size();
    vector<bool> vis(n);
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = true;
        }
        p ^= 1;
    }
    return p;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    auto as = a,bs = b;
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    if(as != bs){
        cout<<"NO\n";
        return;
    }
    ll t1 = 0,t2 = 0;
    for(int i=0;i<n;i++){
        a[i] = lower_bound(as.begin(),as.end(),a[i]) - as.begin();
        b[i] = lower_bound(bs.begin(),bs.end(),b[i]) - bs.begin();
    }
    if(parity(a) == parity(b)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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