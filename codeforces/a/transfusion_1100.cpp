#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int n){
    vector<ll> arr(n);
    ll tot = 0;
    for(int i = 0; i < n; i++){ 
        cin >> arr[i];
        tot += arr[i]; 
    }
    
    if (tot % n){
        cout << "No\n";
        return;
    }
    ll div = tot / n;

    for(int i = 2; i < n; i++){
        if (arr[i-2] == div){
            continue;
        }else if (arr[i-2] < div){
            ll d = div - arr[i-2];
            arr[i-2] = div;
            arr[i] -= d;
        }else{
            ll d = arr[i-2] - div;
            arr[i-2] = div;
            arr[i] += d;
        }
    }
    for (ll num: arr){
        if (num != div){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        solve(n);
    }
    return 0;
}