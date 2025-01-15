#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        for (int i = 0, a = 1; i < n; i++, a+=2){
            cout << a << " ";
        }
        cout << "\n";
    }
    return 0;
}