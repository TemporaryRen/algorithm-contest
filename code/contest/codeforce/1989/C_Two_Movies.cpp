#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 2e5 + 1;
int a[MX],b[MX];

bool check(int rating){

}
void solve(){
    int n;
    cin>>n;
    int ansa = 0;
    int ansb = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i] == 1 && b[i] != 1){
            ansa += 1;
        }
        if(b[i] == 1 && a[i] != 1){
            ansb += 1;
        }
        
    }
    for(int i=0;i<n;i++){
        if(a[i] == 1 && b[i] != 1){
            continue;
        }
        if(b[i] == 1 && a[i] != 1){
            continue;
        }
        if(a[i] == 1 && b[i] == 1){
            if(ansa >= ansb){
                ansb ++;
            }else{
                ansa ++;
            }
        }

        if(a[i] == -1 && b[i] == -1){
            if(ansa >= ansb){
                ansa --;
            }else{
                ansb --;
            }
        }
    }
    cout<<min(ansa,ansb)<<"\n";
    
    

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