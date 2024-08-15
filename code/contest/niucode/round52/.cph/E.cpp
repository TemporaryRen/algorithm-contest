#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
// union find
class UnionFind{
    public:
    vector<int> parent;
    vector<int> size;
    vector<int> mmax;
    UnionFind(int n,vector<int> &v){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        for(int i=0;i<n;i++){
            mmax[i] = v[i];
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return find(parent[x]);
    }
    void unite(int x,int y){
        int px = find(x);
        int py = find(y);
        if(px == py){
            return;
        }
        if(size[px] > size[py]){
            parent[py] = px;
            size[px] += size[py];
            mmax[px] = max(mmax[px],mmax[py]);
        }else{
            parent[px] = py;
            size[py] += size[px];
            mmax[py] = max(mmax[px],mmax[py]);
        }
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    UnionFind uf(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i>m;i++){
        int u,v;
        u--;
        v--;
        cin>>u>>v;

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