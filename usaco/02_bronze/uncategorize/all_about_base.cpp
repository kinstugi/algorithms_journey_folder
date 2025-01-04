#include <bits/stdc++.h>
#define MAXB 15000
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int helper(string num, int base){
    return ((num[0] - '0') * base * base) + ((num[1] - '0') * base) + (num[2] - '0');
}

int main(){
    setIO("whatbase");
    int t, x, y;
    string a, b;
    cin >> t;

    while (t--){
        cin >> a >> b;
        x = 10, y = 10;

        while (x <= MAXB && y <= MAXB){
            int num_x = helper(a, x);
            int num_y = helper(b, y);

            if (num_x < num_y){
                x++;
            }else if (num_y < num_x){
                y++;
            }else{
                cout << x << " " << y << endl;
                break;
            }
        }
    }   
    return 0;
}