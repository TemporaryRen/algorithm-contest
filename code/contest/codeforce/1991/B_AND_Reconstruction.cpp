#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++) cin>>a[i];
    vector<int> ans(n);
    ans[0] = a[0];
    for(int i=1;i<n-1;i++){
        ans[i] = a[i-1] | a[i];
    }
    ans[n-1] = a[n-2];
   
    for(int i=1;i<n;i++){
        if((ans[i-1] & ans[i]) != a[i-1]){

            cout<<-1<<"\n";
            return;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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