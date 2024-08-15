#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<string,vector<string>,less<string>> q;
    string ans ="";
    for(int i=0;i<n;i++){
        q.push(a[i]);
    }
    while(!q.empty()){
        string t = q.top();
        q.pop();
        ans += t[0];
        if(t.size() > 1){
            q.push(t.substr(1));
        }
    }
    cout<<ans<<"\n";
    
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}