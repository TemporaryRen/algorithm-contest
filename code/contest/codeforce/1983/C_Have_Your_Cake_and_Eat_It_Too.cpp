#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 2e5 + 1;
ll presum[MX][3];
void solve(){
    int n,t;
    ll tot;
    cin>>n;
    for(int i=0;i<3;i++){
        presum[0][i] = 0;
        for(int j=1;j<=n;j++){
            cin>>t;
            presum[j][i] = presum[j-1][i] + t;
        }
    }
    tot = presum[n][0];
    //i 表示 前面的 j 表示后面的
    int ans[6];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j) continue;
            int l=1,r=n;
            while((presum[l][i]*3<tot)){
                l++;
            }
            ans[i*2] = 1;ans[i*2+1] = l;
            while((presum[n][j]-presum[r-1][j])*3<tot){
                r--;
            }
            ans[j*2] = r;ans[j*2+1] = n;
            int v = 3 - i - j;
            ans[v*2] = l+1;ans[v*2+1] = r-1;
            if((l+1) <= (r-1) && (presum[r-1][v] - presum[l][v]) * 3 >= tot){
                for(int i=0;i<6;i++){
                    if(i>0) cout<<" ";
                    cout<<ans[i];
                }
                cout<<"\n";
                return;
            }
        }
    }
    cout<<-1<<"\n";
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