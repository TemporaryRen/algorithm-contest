#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int a,b,n;
    cin>>a>>b>>n;
    ll c = n / 3;
    ll t = min(c,(ll)b/2);
    n -= 3 * t;
    if(n <= a){
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