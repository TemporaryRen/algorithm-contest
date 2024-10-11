#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    if(k==1){
        cout<<n<<"\n";
        return;
    }
    int top = 1;
    while(n>=pow(k,top)) top++;
    for(int i=top-1;i>0;i--){
        int p = pow(k,i);
        ans += n/p;
        n = n%p;
    }
    ans += n;

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