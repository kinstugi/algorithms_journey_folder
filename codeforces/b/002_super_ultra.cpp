#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(int num){
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0) return false;
    }
    return true;
}

void solve(int n){
    vector<int> evens, res;
    int last_odd = 1;
    for (int i = 1; i <= n; i++){
        if (i % 2){
            res.push_back(i);
            last_odd = i;
        }else{
            evens.push_back(i);
        }
    }

    for(int num: evens){
        if (!isPrime(num + last_odd)){
            res.push_back(num);
            last_odd = num;
            break;
        }
    }

    if (last_odd % 2){
        cout << -1 << "\n";
        return;
    }
    for (int num: res)
    cout << num << " ";
    for (int num: evens){
        if (num == last_odd) continue;
        cout << num << " ";
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("sample.in", "r", stdin);

    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        solve(n);
    }
    return 0;
}