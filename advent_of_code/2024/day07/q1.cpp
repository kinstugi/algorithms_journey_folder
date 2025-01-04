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
            }else{
                res *= nums[i];
            }
        }
        return res == total;
    }
    ops.push_back(0); // addition
    bool res = isFeasible(total, nums, ops);
    if(res){ return true; }
    ops.pop_back();

    ops.push_back(1);
    res = isFeasible(total, nums, ops);
    ops.pop_back();
    return res;
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