#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    int b3 = a1 + a2,  c3 = a4 - a2;
    int r1 = 1, r2 = 0;
    
    r1 += a4 == (a2 + b3);
    r1 += a5 == (b3 + a4);

    r2 += a4 == (a2 + c3);
    r2 += a5 == (c3 + a4);

    cout << max(r1, r2) << "\n";
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}