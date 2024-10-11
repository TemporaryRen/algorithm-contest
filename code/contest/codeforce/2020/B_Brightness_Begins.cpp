#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
1. Each light bulb will be operated on an almost even number if times becasue if i is a divisor of x.then x/i is also a divisor of x.
2. The number of operations performed on perfect squares is always an odd number
3. Light bulbs operated an even number of times will end up on,while the thos operated an odd numbner of times will end up off
*/
void solve(){t
    ll k;
    cin>>k;
    ll i = pow(k,0.5);
    while(i*i-i < k) i++;
    ll t = (i-1) * (i-1) - i + 1;
    ll ans = (k-t) + (i-1) * (i-1);
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