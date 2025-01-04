#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string file = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!file.empty()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

bool isFeasible (ll total, vector<ll> &nums, vector<ll> &ops){
    // we will only use  + = 0 and * = 1
    if (ops.size() == nums.size() - 1){
        ll res = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (ops[i-1] == 0){
                res += nums[i];
            }else if (ops[i-1] == 1){
                res *= nums[i];
            }else{
                int digit_cnt = 0;
                int b = nums[i];
                while(b){
                    digit_cnt++;
                    b /= 10;
                }
                res = res * pow(10, digit_cnt) + nums[i];
            }
        }
        return res == total;
    }

    for (int i = 0; i < 3; i++){
        ops.push_back(i); //  0 = addition, 1 = multiply, 2 = concat
        bool res = isFeasible(total, nums, ops);
        if(res){ return true; }
        ops.pop_back();
    }

    return false;
}

int main(){
    setIO("actual");
    string s;

    ll res = 0;
    while(getline(cin , s)){
        istringstream iss(s);
        ll total, a;
        char ch;
        iss >> total >> ch;
        vector<ll> arr, ops;

        while(iss >> a){
            arr.push_back(a);
        }

        if (isFeasible(total, arr, ops)){
            res += total;
        }
    }
    cout << res << endl;
    return 0;
}