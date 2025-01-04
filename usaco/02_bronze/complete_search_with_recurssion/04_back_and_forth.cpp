#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

set<ll> possible;

void recur(ll trips_left, const vector<ll> &buckets_here, const vector<ll> &buckets_there, ll tank_here, ll tank_there){
    if (trips_left == 0){
        possible.insert(tank_here);
        return;
    }

    for (ll taken_idx = 0; taken_idx < buckets_here.size(); taken_idx++){
        ll bucket = buckets_here[taken_idx];

        vector<ll> new_bucket_destination(buckets_there);
        new_bucket_destination.push_back(bucket);

        vector<ll> new_bucket_source;
        for ( ll i = 0; i < buckets_here.size(); i++){
            if (i == taken_idx) continue;
            new_bucket_source.push_back(buckets_here[i]);
        }

        ll new_tank_here = tank_here - bucket;
        ll new_tank_there = tank_there + bucket;

        recur(trips_left-1, new_bucket_destination, new_bucket_source,  new_tank_there, new_tank_here);
    }
}

int main(){
    setIO("backforth");
    
    vector<ll> barn1(10), barn2(10);
    for (int i = 0; i < 10; i++) { cin >> barn1[i]; }
    for (int i = 0; i < 10; i++) { cin >> barn2[i]; }

    recur(4, barn1, barn2, 100, 100);
    cout << possible.size() << endl;
    return 0;
}