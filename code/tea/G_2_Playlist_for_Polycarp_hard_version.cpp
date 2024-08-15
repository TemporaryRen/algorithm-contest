#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 52;
pair<int,int> a[MX];
int c[MX][MX][MX][4];
int cnt[4];
void solve(){
    int n,T;
    cin>>n>>T;
    fill(cnt,cnt+4,0);
    for(int i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        cnt[t2] += 1;
        a[i]={t1,t2};
    }
    c[1][0][0][1]=1;
    c[0][1][0][2]=1;
    c[1][0][1][3]=1;
    for(int i=1;i<=cnt[1];i++){
        for(int j=1;j=<cnt[2];j++){
            for(int k=1;k<=cnt[3];k++){
                c[i][j][k][3] = c[i][j][k-1][1] + c[i][j][k-1][2];
            }
        }
    }
    ll ans1 = 0;
    for(int i=1;i<=3;i++){
        ans += c[cnt[1]][cnt[2]][cnt[3]][i];
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