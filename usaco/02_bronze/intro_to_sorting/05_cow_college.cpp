#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> fees(n);

    for (int i = 0; i < n; i++) { cin >> fees[i]; }
    sort(fees.begin(), fees.end());

    ll mx_profit = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        ll cur_profit = fees[i] * (n - i);
        if (mx_profit < cur_profit){
            mx_profit = cur_profit;
            cnt = fees[i];
        }

    }

    cout << mx_profit << " " << cnt << endl;
    return 0;
}