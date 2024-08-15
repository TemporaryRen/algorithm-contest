#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 501;
int matix[MX][MX];
int caps[MX][MX];
void solve(){
    int n,m,k,t;
    string s;
    cin>>n>>m>>k;
    // 从 n * m 中的矩阵中 的 k * k 子数组
    // 其个数 为 pn * pm
    int pn = n - k + 1;
    int pm = m - k + 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matix[i][j];
        }
    }
    ll d = 0;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++) {
            t = s[j] - '0';
            d += matix[i][j] * (t == 1 ? 1 : -1);
            caps[i][j] = (t == 1 ? 1 : -1);
    
        }
    }
    int plen = pn * pm;
    int ggcd = 0;
    for(int i=0;i<plen;i++){
        int rowi = i / pm;
        int coli = i % pm;
        ll ssum = 0;
        for(int ri=rowi;ri<rowi+k;ri++){
            for(int ci=coli;ci<coli+k;ci++){
                ssum += caps[ri][ci];
            }
        }
        ggcd = gcd(ggcd,ssum);
    }
    if(d == 0 || (ggcd != 0 && d % ggcd == 0)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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