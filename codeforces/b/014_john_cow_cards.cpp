#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(n*m);

    for (int i = 1,c = 0; i <= n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[c].first;
            arr[c].second = i;
            c++;
        }
    }

    sort(arr.begin(), arr.end());
    vector<int> res;
    for (int i = 0; i < n; i++){
        int id = i, cur = arr[i].second;
        for (int j = 0; j < m; j++){
            if (cur != arr[id].second){
                cout << -1 << "\n";
                return;
            }
            id += n;
        }
        res.push_back(cur);
    }
    
    for(int num: res)
    cout << num << " ";
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