#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<vector<char>> a(2,vector<char>(n));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i>0 && i<n-1 && a[0][i] == '.' && a[1][i+1] == 'x' 
            && a[1][i-1] == 'x' && a[1][i] == '.' && a[0][i-1] == '.' && a[0][i+1] == '.') 
            ans++;
        if(i>0 && i<n-1 && a[1][i] == '.' && a[0][i+1] == 'x' 
            && a[0][i-1] == 'x' && a[0][i] == '.' && a[1][i-1] == '.' && a[1][i+1] == '.') 
            ans++;
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