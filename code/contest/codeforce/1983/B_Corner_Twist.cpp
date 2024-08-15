#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 501;
int a[2][MX][MX];
void solve(){
    int m,n;
    cin>>m>>n;
    for(int k=0;k<2;k++){
        for(int i=0;i<m;i++){
            string s;
            cin>>s;
            for(int j=0;j<n;j++){
                a[k][i][j] = s[j] - '0';
            }
        }
    }

    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            int diff = a[1][i][j] - a[0][i][j];
            a[0][i][j+1] -= diff;
            a[0][i+1][j] -= diff;
            a[0][i+1][j+1] += diff;
        }
    }

    for(int i=0;i<m;i++){
        if(abs(a[0][i][n-1]-a[1][i][n-1])%3){
            cout<<"NO\n";
            return;
        }
    }
    for(int j=0;j<n;j++){
        if(abs(a[0][m-1][j]-a[1][m-1][j])%3){
            cout<<"NO\n";
            return;
        }
    }
    
    cout<<"YES\n";
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