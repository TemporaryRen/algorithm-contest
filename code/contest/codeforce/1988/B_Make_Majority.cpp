#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zcnt = 0;
    int ocnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') ocnt++;
        else if(i==0 || s[i-1] != '0'){
            zcnt ++;
        }
    }
    if(zcnt < ocnt){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
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