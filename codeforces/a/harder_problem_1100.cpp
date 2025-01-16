#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    set<int> rem, seen;
    for (int i = 1; i <= n; i++){ rem.insert(i); }
    vector<int> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (rem.count(arr[i])){ rem.erase(arr[i]); }
    }

    vector<int> res(n);
    set<int>::iterator it = rem.begin();

    for (int i = 0; i < n; i++){
        if (seen.count(arr[i])){
            res[i] = *it;
            ++it;
        }else{
            seen.insert(arr[i]);
            res[i] = arr[i];
        }
    }

    for (int num: res)
    cout << num << " ";
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}