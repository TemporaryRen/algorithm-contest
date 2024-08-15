#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(!b.empty() && b.back() == a[i] && a[i] >= 0){
            b.pop_back();
        }else{
            b.push_back(a[i]);
        }
    }
    int len = b.size();
    map<int,int> m;
    vector<int> c;
    for(int i=0;i<len;i++){
        if(b[i] >= 0){
            if(m.find(b[i]) == m.end()){
                m[b[i]] = 1;
            }else{
                m[b[i]]++;
            }
        }
    }
    map<int,int> mrm;
    for(int i=0;i<len;i++){
        if(b[i] < 0){
            int t = (~b[i]) + 1;
            if(b[i] + t > 0){
                if(m.find(t) != m.end() && m[t] > 0){
                    if(mrm.find(t) == mrm.end()){
                        mrm[t] = 1;
                    }else{
                        mrm[t]++;
                    }
                    if(mrm.find(b[i]) == mrm.end()){
                        mrm[b[i]] = 1;
                    }else{
                        mrm[b[i]]++;
                    }
                }
            }
        }
    }

    for(int i=0;i<len;i++){
        int x = b[i];
        if(mrm.find(x) != mrm.end() && mrm[x] > 0){
            mrm[x]--;
            continue;
        }
        c.push_back(x);
    }
    int ans = c.size();
    int l = 0;
    int r = c.size() - 1;
    while(l < r){
        if(c[l] + c[r] <= 0){
            ans-=2;
            l++;
            r--;
        }else{
            r--;
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