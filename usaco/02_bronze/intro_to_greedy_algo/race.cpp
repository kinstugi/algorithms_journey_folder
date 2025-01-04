#include <iostream>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


int solve(int max_speed, int max_dis){
    int time = 0;
    int speed_up_dist = 0, slow_down_dist = 0;

    for (int cur_speed = 1;; cur_speed++){
        speed_up_dist += cur_speed;
        time++;
        if (speed_up_dist + slow_down_dist >= max_dis)
        return time;

        if (cur_speed >= max_speed){
            slow_down_dist += cur_speed;
            time++;

            if (speed_up_dist + slow_down_dist >= max_dis)
            return time;
        }
    }
    return time;
}

int main(){
    setIO("race");
    int k, n;
    cin >> k >> n;

    for (int i = 0; i < n; ++i){
        int mx_speed;
        cin >> mx_speed;
        cout << solve(mx_speed, k) << endl;
    }
    return 0;
}