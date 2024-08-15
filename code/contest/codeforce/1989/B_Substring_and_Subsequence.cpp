#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 105;

void solve(){
    string a,b;
    cin>>a>>b;
    int F[MX][MX];
    for(int k=0;k<MX;k++){
        for(int k2=0;k2<MX;k2++){
            F[k][k2] = 0;
        }
    }
    int mmax = 0;
    for(int i=0;i<b.size();i++){
        char bc = b[i];
        for(int j=0;j<a.size();j++){
            char ac = a[j];
            if(bc == ac){
                F[i+1][j+1] = max(F[i][j]+1,F[i+1][j]);
            }else{
                F[i+1][j+1] = F[i+1][j];
            }
            mmax = max(mmax,F[i+1][j+1]);
        }
        
    }
    cout<<(a.size() + b.size() - mmax)<<"\n";
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