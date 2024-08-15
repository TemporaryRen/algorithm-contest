#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

map<pair<ll, ll>, pair<ll, ll>> mem;

pair<ll,ll> f(ll n,ll k){
    // k == 0 时，只有 0 能满足
    if(k == 0) return {1,0};
    // k > n 了 肯定都满足
    if(k >= __bit_width(n)) return {n+1,0};
    //拆分
    ll high = 1LL << (__bit_width(n) - 1);
    if (mem.count({n, k})){
		return mem[{n, k}];
	}
    ll left = high - 1;
    ll right = n - high;
    auto l = f(left,k);
    auto r = f(right,k-1);
    //左边满足的数
    ll left_count = __bit_width(left) <= k ? left + 1 : 0;
    //右边满足的数
    //中间的数
    ll mid_ans = ((l.second % MOD) + (r.second % MOD)) % MOD;
    ll ln = l.first;
    if(left_count == left + 1){
        ln = ln + r.first;
    }else{
        mid_ans = (mid_ans + (((1+r.first)%MOD) * (r.first % MOD) / 2) ) % MOD;
    }
    mem[{n, k}] = {ln, mid_ans%MOD};
    return {ln,mid_ans%MOD};
}

void solve(){
    ll n,k;
    cin>>n>>k;
    auto t = f(n-1,k);
    ll ans = t.second;
    ll other =  (((1+t.first) % MOD) * (t.first % MOD) / 2)% MOD;
    ans = (ans + other) % MOD;
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