#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> cows(n);

    for (int i = 0; i < n; ++i)
    cin >> cows[i];

    ll mx_profit = 0, mx_per_cow = 0;
    sort(cows.begin(), cows.end());

    for (int i = 0; i < n; ++i){
        ll cur = cows[i] * (n - i);
        if (cur > mx_profit){
            mx_profit = cur;
            mx_per_cow = cows[i];
        }
    }
    
    cout << mx_profit << " " << mx_per_cow << endl;

    return 0;
}