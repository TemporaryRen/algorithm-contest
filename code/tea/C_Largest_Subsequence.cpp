#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<int> stk;
    set<int> com;
    char mmax = 'a';
    for(int i=0;i<n;i++){
        if(s[i] > mmax){
            mmax = s[i];
        }
        while(!stk.empty() && s[stk.top()] < s[i]){
            com.insert(stk.top());
            stk.pop();
        }
        stk.push(i);
    }
    char start = 'a';
    int ans = 0;
    for(int i=0;i<n;i++){
        char now;
        if(com.find(i) != com.end()){
            now = s[i];
        }else{
            now = s[stk.top()];
            stk.pop();
            if(now != mmax) ans++;
        }
        if(now < start){
            cout<<-1<<"\n";
            return;
        }else{
            start = now;
        }
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