#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, tmp, odds = 0, even = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        even += tmp % 2 == 0;
        odds += tmp % 2;
    }

    odds += even > 0;
    if (even == 0)
    odds--;

    cout << odds << "\n";
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