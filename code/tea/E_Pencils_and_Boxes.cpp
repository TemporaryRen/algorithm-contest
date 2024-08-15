#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,k,d;
    cin>>n>>k>>d;
    if(k==1){
        cout<<"YES\n";
        return;
    }
    vector<int> a(n+1);
    for(int  i=1;i<=n;i++) cin>>a[i];
    a[0] = -1;
    sort(a.begin(),a.end());
    int left = 0;
    vector<bool> dp(n+1,false);
    dp[0] = true;
    int l = 1;
    vector<int> preffix(n+2,0);
    preffix[0] = 0;
    preffix[1] = 1;
    for(int i=1;i<=n;i++){
        while(a[i]-a[l]>d) l+=1;
        if((i-k>l-2) && preffix[i-k+1] - preffix[l-1] > 0) dp[i] = true;
        preffix[i+1] = preffix[i] + (dp[i] ? 1 : 0);
    }
    if(dp[n]){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}