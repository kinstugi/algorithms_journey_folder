#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

template <typename T> void reverse_seg(vector<T> &arr, int start, int end){
    int l = start, r = end;
    while (l < r){
        swap(arr[l], arr[r]);
        l++; r--;
    }
}

int main(){
    setIO("swap");
    int n, k, a1, a2, b1, b2;
    cin >> n >> k;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    vector<int> cows(n);
    for (int i = 1; i <= n; i++){ cows[i-1] = i; }

    set<vector<int>> seen{cows};
    while(1){
        reverse_seg(cows, a1-1, a2-1);
        reverse_seg(cows, b1-1, b2-1);
        if (seen.count(cows)) break;
        seen.insert(cows);
    }

    int cycle_count = seen.size();
    int swaps_left = k % cycle_count;
    for (int i = 0; i < swaps_left; i++){
        reverse_seg(cows, a1-1, a2-1);
        reverse_seg(cows, b1-1, b2-1);
    }
    for(int a: cows)
    cout << a << "\n";
    return 0;
}