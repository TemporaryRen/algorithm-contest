#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"1\n1";
    }else if(n==2){
        cout<<"2\n1 2";
    }else if(n==3){
        cout<<"2\n1 2 2";
    }else if(n == 4){
        cout<<"3\n1 2 2 3";
    }else if(n==5){
        cout<<"3\n1 2 2 3 3";
    }else{
        cout<<"4\n";
        for(int i=1;i<=n;i++) cout<<(i%4 + 1)<<" ";
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