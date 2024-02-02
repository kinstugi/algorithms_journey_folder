#include <iostream>
#include <vector>
#include <algorithm>


long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
    int i1 = -1;
    int m1 = 0, m2 = 0;

    for(int i = 0; i < n; ++i){
        if(numbers[i] > m1){
            m1 = numbers[i];
            i1 = i;
        }
    }

    for(int i = 0; i < n; ++i){
        if(i == i1) continue;
        if( numbers[i] > m2){
            m2 = numbers[i];
        }
    }

    return (long long)m1 * m2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
