#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, tmp;
    cin >> n;
    map<int, int> mp;

    int twos = -1;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        mp[tmp]++;

        if (mp[tmp] >= 2 && twos == -1){
            twos = tmp;
            mp[tmp] -= 2;
        }
    }

    for (auto &[k, v]: mp){
        if (v == 0) continue;
        if (mp.count(2*k) && mp[2*k]){
            cout << twos << " " << twos << " " << k << " " << 2*k << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("sample.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}