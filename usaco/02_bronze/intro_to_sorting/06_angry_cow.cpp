#include <bits/stdc++.h>
using namespace std;

int bales[1001], n;

int detonate(int startIdx, int direction){
    int radius = 1;
    int prev = startIdx;

    while(true){
        int next = prev;
        while(next + direction >= 0 && next + direction < n && abs(bales[next + direction] - bales[prev]) <= radius){
            next += direction;
        }
        if (next == prev) { break; }
        prev = next;
        radius++;
    }

    return abs(prev - startIdx);
}

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("angry");
    cin >> n;

    for (int i = 0; i < n; i++){ cin >> bales[i]; }
    sort(bales, bales + n);

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, detonate(i, -1) + detonate(i, 1) + 1);
    }
    cout << ans << endl;
    return 0;
}