#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n; cin >> n;
    vector<ll>a(n),b(n);
    for (ll &x:a) {cin >> x;}
    for (ll &y:b) {cin >> y;}
    ll sum = 0;
    vector<ll> coeffs;
    for (ll i = 0; i < n; i++){
        coeffs.push_back((i+1)*(n-i)*a[i]);
    }
    sort(coeffs.begin(),coeffs.end());
    sort(b.begin(), b.end(), greater<int>());
    for (ll i = 0; i < n; i++){
        sum += coeffs[i]*b[i];
    }
    cout << sum;
}