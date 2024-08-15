#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> preffix1(26,vector<int>(n+1,0));
    vector<vector<int>> preffix2(26,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        char c1 = a[i-1];
        char c2 = b[i-1];
        for(int j=0;j<26;j++){
            preffix1[j][i] += preffix1[j][i-1];
            preffix2[j][i] += preffix2[j][i-1];
        }
        preffix1[c1-'a'][i] ++;
        preffix2[c2-'a'][i] ++;
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ans = 0;
        for(int i=0;i<26;i++){
            ans += abs((preffix1[i][r] - preffix1[i][l-1]) - (preffix2[i][r] - preffix2[i][l-1]));
        }
        cout<<ans/2<<"\n";
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