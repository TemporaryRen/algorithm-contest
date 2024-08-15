#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i] = -1;
    for(int i=y-3;i>=0;i-=2){
        a[i] = 1;
    }
    for(int i=x+1;i<n;i+=2){
        a[i] = 1;
    }
    for(int i=y-1;i<x;i++){
        a[i] = 1;
    }
    int cnt = x-y+1;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
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