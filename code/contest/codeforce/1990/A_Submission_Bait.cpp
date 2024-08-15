#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int cnt = 1;
    int pre = a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i] != pre){
            if(cnt % 2 == 1){
                cout<<"YES\n";
                return;
            }else{
                cnt = 1;
                pre = a[i];
            }
            
        }else{
            cnt++;
        }
    }
    if(cnt%2 == 1){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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