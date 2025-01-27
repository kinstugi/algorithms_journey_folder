#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, s, r;
    cin >> n >> s >> r;
    int div = r / (n-1);
    int rem =  r % (n-1);

    cout << s - r << " ";
    for (int i = 0 ; i < (n-1); i++){
        cout << div + (rem > 0 ? 1 : 0) << " ";
        rem--;
    }
    cout << "\n";
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