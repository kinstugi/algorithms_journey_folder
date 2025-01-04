#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;

    vector<ll> shows(n);

    for (int i = 0; i < n; ++i)
    cin >> shows[i];

    sort(shows.begin(), shows.end());

    ll last_day = shows[0];
    ll cost = k + 1;

    for (ll d: shows){
        if (d - last_day < k + 1){
            cost += d - last_day;
        }else{
            cost += k + 1;
        }
        last_day = d;
    }
    cout << cost << "\n";
    return 0;
}