#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
map<int,int> mmp;

void cal(int n,int m,vector<ll> &p1,const vector<vector<int>> a){
    int n1 = n,m1 = m;
    for(int i=0;i<(n+m);i++){
        if(n1 == 0 && m1 == 0){
            p1[i+1] = p1[i];
            mmp[i+1] = 0;
        }
        else if(n1 == 0 || (m1 != 0 && a[i][1] > a[i][0])){
            p1[i+1] = p1[i] + a[i][1];
            m1 --;
            mmp[i+1] = 2;

        }
        else if(m1 == 0 || (a[i][0] > a[i][1])){
            p1[i+1] = p1[i] + a[i][0];
            mmp[i+1] = 1;
            n1 --;
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int p = n + m + 1;
    mmp.clear();
    vector<vector<int>> a(p,vector<int>(2));
    for(int k=0;k<2;k++)
        for(int i=0;i<p;i++){
            cin>>a[i][k];
        }
    vector<ll> p1(p+1,0);
    vector<ll> p2(p+1,0);
    vector<ll> p3(p+1,0);
    cal(n+1,m,p2,a);
    cal(n,m+1,p3,a);
    cal(n,m,p1,a);
    for(int i=1;i<=p;i++){
        ll t1 = p1[i-1];
        if(mmp[i] == 1){
            t1 += p2[p] - p2[i];
        }else if(mmp[i] == 2){
            t1 += p3[p] - p3[i];
        }
        cout<<t1<<" ";
    }
    cout<<"\n";
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