#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool just3_6(ll num){
    int sz = 0;
    bool flag = true;
    while(num){
        int r = num % 10;
        num /= 10;
        if (r != 3 && r != 6) flag = false;
    }
    return flag;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        if (n == 1 || n == 3){
            cout << -1 << "\n";
            continue;
        }

        if (n % 2){
            for (int i = 0; i < n-5; i++)
            cout << 3;
            cout << "36366\n";
        }else{
            for(int i = 0; i < n-2; i++)
            cout << 3 ;
            cout << "66\n";
        }
    }
    return 0;
}