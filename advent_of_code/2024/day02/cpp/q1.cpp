#include <bits/stdc++.h>
using namespace std;

void setIO(string file=""){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (file.size()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

bool isArrayIncreasing(vector<int> &arr, int &mxGap){
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] <= arr[i-1]) return false;
        mxGap = max(mxGap, arr[i] - arr[i-1]);
    }
    return true;
}

bool isArrayDecreasing(vector<int> &arr, int &mxGap){
    for (int i =1; i < arr.size(); i++){
        if (arr[i] >= arr[i-1]) return false;
        mxGap = max(mxGap, arr[i-1] - arr[i]);
    }
    return true;
}

int main(){
    setIO("test");
    string line;
    int num;

    int ans = 0;
    while(getline(cin, line)){
        if (!line.size()) break;
        istringstream iss(line);
        vector<int> level;

        while(iss >> num){
            level.push_back(num);
        }

        if (!level.size()) { continue; }

        int mxGap1 = 0, mxGap2 = 0;
        if (isArrayDecreasing(level, mxGap1)){
            if (mxGap1 < 4) { ans ++; }
        }else if (isArrayIncreasing(level, mxGap2)){
            if (mxGap2 < 4) {ans++;}
        }

    }

    cout << ans << endl;
    return 0;
}