#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll pow10(int exp){
    ll prd = 1;
    for (int i = 0; i < exp; i++){
        prd *= 10;
    }
    return prd;
}

int main(){
    int t;
    cin >> t;
    ll k;
    while (t--){   

        cin >> k;
        int n = 1;
        ll res = n * 9 * pow10(n-1);
        while (k > res){
            k -= res;
            n++;
            res = n * 9 * pow10(n-1);
        }

        ll num = (k-1)/ n + pow10(n-1);
        int loc = (k-1) % n;
        cout << to_string(num)[loc] << endl;
    }

    return 0;
}