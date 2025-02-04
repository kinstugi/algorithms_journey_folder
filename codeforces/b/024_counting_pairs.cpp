#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll solve(const vector<ll> &arr, int n, ll tot, ll x){
    ll ans = 0;
    int j = 0;

    for (int i = n-1; i > -1; i--){    
        while(j < n && (tot - arr[i] - arr[j]) >= x){
            j++;
        }
        ans += n -j ;
    }

    for (int i = 0; i < n; i++){
        if (tot - arr[i] - arr[i] < x)
        ans--;
    }
    return ans / 2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);
    
    ll t, n , x, y;
    cin >> t;

    while(t--){
        cin >> n >> x >> y;
        vector<ll> arr(n);
        ll tot = 0;

        for (int i = 0; i < n; i++){
            cin >> arr[i];
            tot += (ll)arr[i];
        }

        sort(arr.begin(), arr.end());
        cout << solve(arr,n, tot,y+1) - solve(arr,n, tot, x) << "\n";
    }
    return 0;
}