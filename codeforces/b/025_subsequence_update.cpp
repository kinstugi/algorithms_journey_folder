#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++)
    cin >> arr[i];

    vector<ll> A, B, C;
    for (int i = 1; i < l; i++)
    A.push_back(arr[i]);

    ll tot = 0;
    for (int i = l; i <= r; i++){
        B.push_back(arr[i]);
        tot += arr[i];
    }

    for (int i = r+1; i <= n; i++)
    C.push_back(arr[i]);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int i = B.size() - 1;
    ll cur = tot, ans =  tot;
    for (int num: A){
        if(num > B[i] || i < 0) break;
        cur -= B[i];
        cur += num;
        i--;
    }
    ans = min(ans, cur);

    i = B.size()-1;
    cur = tot;
    for (int num: C){
        if (num > B[i] || i < 0) break;
        cur -= B[i];
        cur += num;
        i--;
    }
    ans = min(ans, cur);
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("sample.in", "r", stdin);

    int t;
    cin >> t;

    while(t--)
    solve();
    return 0;
}