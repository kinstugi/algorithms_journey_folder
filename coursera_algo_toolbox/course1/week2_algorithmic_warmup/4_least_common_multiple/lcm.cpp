#include <iostream>
#include <cassert>

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm_fast(int a, int b){
	return ((long long) a * b) / gcd(a, b);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

void stress_test(){
	for (int i =1; i < 1000; ++i){
		for (int j = i; j < 1000; ++j){
			assert(lcm_naive(i, j) == lcm_fast(i, j));
		}
	}
}

int main() {
  int a, b;
  //stress_test();
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
