#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 501;
int X[MX],Y[MX];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>X[i]>>Y[i];
    }
    for(int i=0;i<n;i++){
        if(Y[i] >= -1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
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