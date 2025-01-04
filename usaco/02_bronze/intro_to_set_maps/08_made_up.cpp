#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO();
    int n; cin >> n;
    vector<ll>  B(n);
    map<ll, ll> mpA,  mpC;

    for (int i = 0; i < n; i++){
        ll tmp; 
        cin >> tmp;
        mpA[tmp]++; 
    }
    for (int i = 0; i < n; i++){ cin >> B[i]; }
    for (int i = 0; i < n; i++){
        ll tmp; 
        cin >> tmp;
        mpC[tmp]++; 
    }

    

    for (int i = 0; i < n; i++){
        if (!mpA.count(B[i])){
            B[i] = INT_MIN;
        }
    }
    ll ans = 0;

    for (int i = 0; i < n; i++){
        if (B[i] == INT_MIN) continue;
        ans += mpA[B[i]] * mpC[i+1];
    }

    cout << ans << endl;
    return 0;
}