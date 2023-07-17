#include <bits/stdc++.h>

const int MAXN = 1000005;
const long long MAXX = 9e18; 

int N, K, H[MAXN];
long long DP[MAXN];

int main() {
	std::cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		std::cin >> H[i];

	DP[1] = 0;
	for (int i = 2; i <= N; i++) 
		DP[i] = MAXX; 
	for (int i = 2; i <= N; i++) 
		for (int j = 1; j <= K; j++)
			if (i - j >= 1) 
				DP[i] = std::min(DP[i], DP[i - j] + abs(H[i - j] - H[i]));

	std::cout << DP[N];
	return 0;
}
