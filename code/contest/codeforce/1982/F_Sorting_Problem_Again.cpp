#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1e5 + 1;
int a[MX],b[MX];
const int TMX = 2 << __bit_width(MX)
int tree[TMX];




void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0) b[i] = a[i] = a[i-1];
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