#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    cin >> arr[i];

    for (int i = 1; i < n; i++){
        int mn = min(arr[i-1], arr[i]);
        arr[i-1] -= mn;
        arr[i] -= mn;

        if (arr[i] < arr[i-1]){
            cout << "No\n";
            return;
        }
    }

    cout << "yes\n";
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