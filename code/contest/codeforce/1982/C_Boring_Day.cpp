#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,l,r,t;
const int MX = 1e5 + 1;
ll preffix[MX];
void solve(){
    cin>>n>>l>>r;
    preffix[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>t;
        preffix[i] = t;
        if(i>1) preffix[i] += preffix[i-1];
    }
    ll ans = 0;
    int li = 0;
    for(int i=1;i<=n;i++){
        //从 li 开始向右边找
        int ln = li,rn = i;
        while(ln < rn){
            int mid = ln +(rn - ln)/ 2;
            ll rSum = preffix[i]-preffix[mid];
            if(rSum>=l && rSum<=r){
                ans += 1;
                li = i;
                break;
            }else if(rSum < l){
                rn = mid;
            }else{
                ln = mid + 1;
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