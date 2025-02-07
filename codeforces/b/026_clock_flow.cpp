#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, ai;
    cin >> n;
    bool flag = true;

    for (int i = 0; i < n; i++){
        cin >> ai;
        if (ai <= 2*i || ai <= 2*(n-i-1)){
            flag = false;
        }
    }

    if (!flag)
    cout << "no\n";
    else
    cout << "yes\n";
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