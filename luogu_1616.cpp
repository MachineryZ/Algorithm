#include <iostream>
#include <cmath>

/*
0-1 knapsack

wi: weight of i-th item
vi: value of i-th item
W: total weight of knapsack
f[i,j] max value of first i item in j weights

Transition equation 
f[i,j] = max(f[i-1, j], f[i-1, j-wi] + vi)

state compression
f[j] = max(f[j], f[j - wi] + vi)
*/


int main() {
    int W, n;
    int weight[10005];
    int value[10005];
    int dp[10005];
    std::cin >> W >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> weight[i] >> value[i];
    for (int i = 1; i <= W; i++)
        dp[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= weight[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    std::cout << dp[W] << std::endl;
    return 0;
}