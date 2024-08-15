#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
 * 作者: temporary-case
 * 本题思路:
 * 枚举所有右节点 r ->[1,N] 统计每个右子节点的合法子数组。得出最终结果
 * 对于 一段连续的区间 [l,r] 且 al al+1 al+2 ... ar 都是不同的数，当 x->[l,r] 且 [x,R] 是合法数组时，则
 */
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int> cnt;
    int l = 0,t1=0,t2=0;
    int add = 1;
    ll ans = 0;
    int lt = 0;
    ll cal_cnt = 0;
    for(int i=0;i<n;i++){
        t1++;
        if(cnt[a[i]]++ == 0){
            t2++;
        }
        while(t1-t2>k){
            t1 --;
            if(--cnt[a[l++]] == 0){
                t2 --;
            }
            add = 1;
            lt = l;
        }
        if(t1 - t2 == k) {
            while(lt<i && cnt[a[lt]] == 1){
                add++;
                lt++;
                cal_cnt++;
            }
            ans += add;
        }


    }
    cout<<cal_cnt<<"\n";
    cout<<ans;
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