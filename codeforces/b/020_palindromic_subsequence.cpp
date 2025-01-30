#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    cout << 1 << " ";
    for (int i = 1; i < n-2; i++)
    cout << i << " ";
    cout << "1 2\n";
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