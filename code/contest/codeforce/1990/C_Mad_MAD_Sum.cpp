#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ssum = accumulate(a.begin(),a.end(),0LL);
    int mmax = 0;
    int setx = 0;
    int cnt = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x = a[i];
        if(mp.find(x) == mp.end()){
            mp[x] = 1;
        }else{
            mp[x] += 1;
        }
        if(mp[x] >= 2 && x > setx){
            setx = x;
        }
        a[i] = setx;
        
    }
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<"\n";
    ssum += accumulate(a.begin(),a.end(),0LL);
    mp.clear();
    setx = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        if(mp.find(x) == mp.end()){
            mp[x] = 1;
        }else{
            mp[x] += 1;
        }
        if(mp[x] >= 2 && x > setx){
            setx = x;
        }
        a[i] = setx;
        
    }
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<"\n";
    ll t = accumulate(a.begin(),a.end(),0LL);
    int diff = n-1;
    while(t > 0){
        ssum += t;
        t -= a[diff];
        diff--;
    }
    cout<<ssum<<"\n";
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