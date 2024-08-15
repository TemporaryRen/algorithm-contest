#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    string s;
    cin>>s;
    int MOD = 1e9+7;
    int n = s.size();
    vector<int> preffix(n+1);
    preffix[0] = 0;
    for(int i=0;i<n;i++){
        preffix[i+1] = preffix[i] + (s[i] == '0' ? -1 : 1);
    }

    map<int,int> cnt;
    cnt[0] = 1;
    ll ans = 0;
    ll f0 = 0;
    for(int i=1;i<=n;i++){
        int x = preffix[i];
        ll t = f0;
        if(cnt.find(x)!=cnt.end()){
            t = (t + cnt[x]) % MOD;
            cnt[x] = (cnt[x] + (i+1) ) % MOD;
            f0 = t;
        }else cnt[x] = i + 1;
        ans = (ans + t) % MOD;
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