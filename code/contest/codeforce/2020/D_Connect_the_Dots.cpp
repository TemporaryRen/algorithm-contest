#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 1;
const int D = 11;
int par[N],siz[N];
int find(int node){
    if(node == par[node]) return node;
    return par[node] = find(par[node]);
}
void union_node(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    par[y] = x;
    siz[x] += siz[y];
}
void reset(int n){
    for(int i=0;i<=n;i++){
        par[i] = i;
        siz[i] = 1;
    }
}
void solve(){
    int n,m,a,d,k;
    cin>>n>>m;
    vector R(n+1,vector(D,0));
    reset(n);
    for(int i=0;i<m;i++){
        cin>>a>>d>>k;
        R[a][d] = max(R[a][d],a + k * d);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<D;j++){
            if(i>j){
                if(R[i-j][j] >= i){
                    union_node(i,i-j);
                    R[i][j] = max(R[i][j],R[i-j][j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(par[i] == i) ans ++;
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