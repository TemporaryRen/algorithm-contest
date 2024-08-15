#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1) {
        cout<<a[0]<<"\n";
        return;
    }
    for(int i=2;i<n;i++){
        if(a[i-2] > a[i]){
            a[i] = a[i-2];
        }
    }
    cout<<a[n-1]<<"\n";
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