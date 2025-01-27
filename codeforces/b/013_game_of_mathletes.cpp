#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, k, tmp, ans = 0;
    cin >> n >> k;
    map<int, int> seen;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        if (seen.count(k - tmp) && seen[k-tmp] > 0){
            ans++;
            seen[k-tmp]--;
        }else
        seen[tmp]++;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}