#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n,k;
    cin>>n>>k;
    int t = n/k;
    vector<vector<char>> a(n,vector<char>(n));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j];
        }
    }
       
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cout<<a[i*k][j*k];
        }
        cout<<"\n";
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