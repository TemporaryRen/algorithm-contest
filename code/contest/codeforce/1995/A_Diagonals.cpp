#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n,k;
    cin>>n>>k;
    int ans = 0;
    if(k==0) {
        cout<<0<<"\n";
        return;
    }
    if(k<=n){
        cout<<1<<"\n";
    }else{
        k -= n;
        ans = 1;
        int start = n - 1;
        while(start > 0 && k>0){
            ans += 1;
            k -= start;
            if(k>0){
                ans ++;
            }
            k -= start;
            start --;
        }
        cout<<ans<<"\n";

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