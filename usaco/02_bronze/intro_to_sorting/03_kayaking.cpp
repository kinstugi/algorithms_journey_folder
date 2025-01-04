#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    int people_count = 2*n, ans = INT_MAX;

    vector<int> people(people_count);

    for (int i = 0; i < people_count; i++){ cin >> people[i]; }
    sort(people.begin(),  people.end());

    for (int i = 0; i < people_count; i++){
        for (int j = i+1; j < people_count; j++){
            vector<int> remaining_people;
            for (int k = 0; k < people_count; k++){
                if (k == i || k == j) continue;
                remaining_people.push_back(people[k]);
            }

            int tot = 0;
            for (int k = 1; k < remaining_people.size(); k += 2){
                tot += remaining_people[k] - remaining_people[k-1];
            }
            ans = min(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}