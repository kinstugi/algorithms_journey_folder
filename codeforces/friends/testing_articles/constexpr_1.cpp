#include <iostream>
#include <array>

constexpr bool _ = false;
constexpr bool X = true;

constexpr size_t N = 16;

using Canvas = std::array<std::array<bool, N>, N>;

constexpr Canvas life {{
    {_,X,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,X,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{X,X,X,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
	{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,},
}};

consteval Canvas updateCanvas(Canvas old){
    Canvas res;
	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			
			int neighborCount = 0;
			for (int dr = r-1; dr < r+2; dr++){
				for (int dc = c-1; dc < c+2; dc++){
					if (dr == r && dc == c) continue;
					int wrappedR = (dr + N) % N;
					int wrappedC = (dc + N) % N;

					neighborCount += static_cast<int>(old[wrappedR][wrappedC]);
				}
			}
			const bool isAlive = old[r][c];
			res[r][c] = neighborCount == 3 || (isAlive && neighborCount == 2);
		}
	}
    return res;
}

int main(){
	constexpr Canvas newLife = updateCanvas(life);
    return newLife[0][1];
}