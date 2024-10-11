#include <bits/stdc++.h>
using namespace std;
#define ll long long

int cal(int bitB,int bitC,int bitD){
    if(bitB == 0){
        if (bitC == 1 && bitD==1) return -1;
        else return bitD;
    }else{
        if(bitC == 0 && bitD == 0) return -1;
        else return abs(bitD - 1);
    }
}
void solve(){
    ll b,c,d;
    cin>>b>>c>>d;
    ll ans = 0;
    for(int i=0;i<64;i++){
        int bitB = (b>>i)&1;
        int bitC = (c>>i)&1;
        int bitD = (d>>i)&1;
        int res = cal(bitB,bitC,bitD);
        if(res == -1){
            cout<<-1<<"\n";
            return;
        }
        ans += res*(1LL<<i);
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