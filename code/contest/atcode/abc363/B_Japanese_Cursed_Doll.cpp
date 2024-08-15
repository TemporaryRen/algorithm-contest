#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void solve(){
    int N,T,P;
    cin>>N>>T>>P;
    vector<int> L(N);
    for(int i=0;i<N;i++) cin>>L[i];
    sort(L.begin(),L.end());
    cout<<max(0,(T-L[N-P]))<<"\n";
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