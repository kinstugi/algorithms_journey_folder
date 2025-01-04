#include <bits/stdc++.h>
using namespace std;

bool is_completely_cooled(const vector<int>& stall_temperatures) {
    for (int temperature : stall_temperatures) {
        if (temperature > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number_of_heat_sources, number_of_air_conditioners;
    cin >> number_of_heat_sources >> number_of_air_conditioners;

    vector<int> stall_temperatures(101, 0);
    for (int i = 0; i < number_of_heat_sources; ++i) {
        int start_heat_source, end_heat_source, heat_level;
        cin >> start_heat_source >> end_heat_source >> heat_level;
        for (int stall = start_heat_source; stall <= end_heat_source; ++stall) {
            stall_temperatures[stall] += heat_level;
        }
    }

    vector<vector<int>> air_conditioners;
    for (int i = 0; i < number_of_air_conditioners; ++i) {
        int start_ac, end_ac, cooling_power, cost;
        cin >> start_ac >> end_ac >> cooling_power >> cost;
        air_conditioners.push_back({start_ac, end_ac, cooling_power, cost});
    }

    int minimum_cost = INT_MAX;
    int number_of_combinations = 1 << number_of_air_conditioners;
    for (int combination = 0; combination < number_of_combinations; ++combination) {
        vector<int> current_stall_temperatures(stall_temperatures);
        int total_cost = 0;

        for (int i = 0; i < number_of_air_conditioners; ++i) {
            if (combination & (1 << i)) {
                total_cost += air_conditioners[i][3];
                for (int stall = air_conditioners[i][0]; stall <= air_conditioners[i][1]; ++stall) {
                    current_stall_temperatures[stall] -= air_conditioners[i][2];
                }
            }
        }

        if (is_completely_cooled(current_stall_temperatures)) {
            minimum_cost = min(minimum_cost, total_cost);
        }
    }

    cout << minimum_cost << endl;
    return 0;
}
