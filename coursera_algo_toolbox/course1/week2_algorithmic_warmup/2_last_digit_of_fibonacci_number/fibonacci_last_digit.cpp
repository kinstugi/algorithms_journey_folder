#include <iostream>
#include <cassert>

const int MOD = 10;
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fib_fast(int n){
	if ( n <= 1) return n;
	int a = 0, b = 1;
	for (int i = 2; i <= n; ++i){
		int c = (a + b) % MOD;
		a = b % MOD;
		b = c;
	}
	return b % 10;
}

void stress_test(){
	for (int i = 1; i < 1000; ++i){
		std::cout << i << '\n';
		assert(fib_fast(i) == get_fibonacci_last_digit_naive(i));
	}
}

int main() {
    int n;
	//stress_test();
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
	int c = fib_fast(n);
    std::cout << c << '\n';
}
