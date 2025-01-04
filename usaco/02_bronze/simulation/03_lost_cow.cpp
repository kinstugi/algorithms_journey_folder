#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("lostcow");
    int fj, bessie;
    cin >> fj >> bessie;

    int cur = fj, total_dis = 0, tmp;
    if (fj == bessie) { cout << 0 << endl; }
    else if (fj < bessie) {
        for (int i = 0; cur != bessie; i++){
            int dd = pow(-1, i) * pow(2, i);
            tmp = min(fj + dd, bessie);
            total_dis += abs(cur - tmp);
            cur = tmp;
        }
    }else{
        for (int i = 0; cur != bessie; i++){
            int dd = pow(-1, i) * pow(2, i);
            tmp = max(fj + dd, bessie);
            total_dis += abs(cur - tmp);
            cur = tmp;
        }
    }
    cout << total_dis << endl;
    return 0;
}